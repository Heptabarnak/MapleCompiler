#include <function/FunctionDefinition.h>
#include "X86_64.h"

using std::string;
using std::map;

X86_64::X86_64(Config *config, map<string, CFG *> &cfgs) : BaseTarget(config, cfgs) {}

void X86_64::parse() {
    open();

    // First the file header
    string header = "\t.file \"" + conf->fileToCompile + "\"\n";
    header += "\t.text\n";
    header += "\t.globl main\n";
    header += "\t.type main, @function\n";

    write(header);

    for (auto cfg : cfgs) {
        currentCFG = cfg.second;

        // Add new label for the function
        write(cfg.first + ":");

        prologue();

        parseBasicBlocks();

        epilogue();
    }

    // It's the end so close the file
    close();
}

void X86_64::compile() {
    if (!system(nullptr)) {
        std::cerr << "[X86_64] Unable to create an executable, system() unavailable" << std::endl;
        throw std::runtime_error("System unavailable");
    }

    // Close .s file
    close();

    int result = system(("as -o " + conf->fileToCompile + ".o " + conf->fileToCompile + ".s").c_str());

    if (result != 0) {
        std::cerr << "[X86_64] Unable to assemble asm" << std::endl;
        throw std::runtime_error("Error while assemble source");
    }

    result = system(("gcc -static -o " + conf->fileToCompile + ".out " + conf->fileToCompile + ".o").c_str());

    if (result != 0) {
        std::cerr << "[X86_64] Unable to link executable" << std::endl;
        throw std::runtime_error("Error while linking executable");
    }
}

void X86_64::prologue() {

    write("\tpushq %rbp");
    write("\tmovq %rsp, %rbp");

    // Now we must add the correct size of variables

    long allocationSize = currentCFG->getAllocationSize();
    string subq = "\tsubq $" + std::to_string(allocationSize) + ", %rsp";

    write(subq);
    write("");

    // Load arguments
    auto args = currentCFG->getFunctionDefinition()->getParams();
    long size = args.size();

    if (size > 0) {
        write("\tmovq %rdi, -" + std::to_string(currentCFG->getOffset(args.at(0)->getName())) + "(%rbp)");
    }
    if (size > 1) {
        write("\tmovq %rsi, -" + std::to_string(currentCFG->getOffset(args.at(1)->getName())) + "(%rbp)");
    }
    if (size > 2) {
        write("\tmovq %rdx, -" + std::to_string(currentCFG->getOffset(args.at(2)->getName())) + "(%rbp)");
    }
    if (size > 3) {
        write("\tmovq %rcx, -" + std::to_string(currentCFG->getOffset(args.at(3)->getName())) + "(%rbp)");
    }
    if (size > 4) {
        write("\tmovq %r8, -" + std::to_string(currentCFG->getOffset(args.at(4)->getName())) + "(%rbp)");
    }
    if (size > 5) {
        write("\tmovq %r9, -" + std::to_string(currentCFG->getOffset(args.at(5)->getName())) + "(%rbp)");
    }
    if (size > 6) {
        // FIXME We should copy from the caller stack to our stack
        // Don't know how to get the caller offset
        for (auto it = args.begin() + 6; it != args.end(); ++it) {
            write("\tpopq -" + std::to_string(currentCFG->getOffset((*it)->getName())) + "(%rsp)");
        }

        std::cerr << "We do not support functions with more than 6 arguments for now, sorry for the inconvenience"
                  << std::endl;
    }

}

void X86_64::epilogue() {
    write("\tleave");
    write("\tret");
    write("");
}

void X86_64::parseBasicBlocks() {
    for (auto &&bb : currentCFG->getBBs()) {

        write("." + bb->label + ":");

        for (auto &&instr : bb->instrs) {
            instrDispacher(instr);
        }

        // Jump to somewhere

        // Last basic block (return value always go to %rax)
        if (bb->exitTrue == nullptr) {
            return;
        }

        if (bb->exitFalse != nullptr) {
            // Conditional jump
            // TODO Check if last instr did a cmp
            // If yes, just do a jne otherwise, do first a cmp
            // For now, we add a cmp with %rax and 0
            write("\tmovq $0, %rbx");
            write("\tcmpq %rax, %rbx");
            write("\tjz ." + bb->exitFalse->label);
        }

        // Unconditional jump
        write("\tjmp ." + bb->exitTrue->label);
    }
}


void X86_64::op(OpInstr *instr) {

    auto left = instr->var1;
    auto right = instr->var2;
    auto dest = instr->var;

    // Move to registers
    write("\tmovq -" + std::to_string(currentCFG->getOffset(left)) + "(%rbp), %rax");
    write("\tmovq -" + std::to_string(currentCFG->getOffset(right)) + "(%rbp), %rbx");

    switch (instr->type) {
        case OpInstr::ADD:
            write("\taddq %rbx, %rax");
            break;
        case OpInstr::SUB:
            write("\tsubq %rbx, %rax");
            break;
        case OpInstr::MULT:
            write("\timulq %rbx, %rax");
            break;
        case OpInstr::DIV:
            write("\tcdq");
            write("\tidivq %rbx");
            break;
        case OpInstr::MOD:
            write("\tcdq");
            write("\tidivq %rbx");
            write("\tmovq %rdx, %rax");
            break;
        case OpInstr::EQUAL_EQUAL:
            write("\tcmpq %rbx, %rax");
            // 0 per default, 1 if equal
            write("\tmovq $0, %rax");
            write("\tmovq $1, %rbx");
            write("\tcmove %rbx, %rax");
            break;
        case OpInstr::LESS_THAN:
            write("\tcmpq %rbx, %rax");
            // 0 per default, 1 if >
            write("\tmovq $0, %rax");
            write("\tmovq $1, %rbx");
            write("\tcmovb %rbx, %rax");
            break;
        case OpInstr::LESS_THAN_OR_EQ:
            write("\tcmpq %rbx, %rax");
            // 0 per default, 1 if <=
            write("\tmovq $0, %rax");
            write("\tmovq $1, %rbx");
            write("\tcmovbe %rbx, %rax");
        case OpInstr::MORE_THAN:
            write("\tcmpq %rbx, %rax");
            // 0 per default, 1 if >
            write("\tmovq $0, %rax");
            write("\tmovq $1, %rbx");
            write("\tcmova %rbx, %rax");
            break;
        case OpInstr::MORE_THAN_OR_EQ:
            write("\tcmpq %rbx, %rax");
            // 0 per default, 1 if >=
            write("\tmovq $0, %rax");
            write("\tmovq $1, %rbx");
            write("\tcmovae %rbx, %rax");
            break;
        case OpInstr::AND:
            write("\tandq %rax, %rbx");
            break;
        case OpInstr::OR:
            write("\torq %rax, %rbx");
            break;
        case OpInstr::XOR:
            write("\txorq %rax, %rbx");
            break;
        case OpInstr::SHIFT_LEFT:
            write("\tshlq %rax, %rbx");
            break;
        case OpInstr::SHIFT_RIGHT:
            write("\tshrq %rax, %rbx");
            break;
    }

    write("\tmovq %rax, -" + std::to_string(currentCFG->getOffset(dest)) + "(%rbp)");
}

void X86_64::loadConst(LoadConstInstr *instr) {
    write("\tmovq $" + std::to_string(instr->value) + ", %rax");
    write("\tmovq %rax, -" + std::to_string(currentCFG->getOffset(instr->var)) + "(%rbp)");
}

void X86_64::call(CallInstr *instr) {
    auto args = instr->arguments;
    long size = args.size();

    if (size > 0) {
        write("\tmovq -" + std::to_string(currentCFG->getOffset(args.at(0))) + "(%rbp), %rdi");
    }
    if (size > 1) {
        write("\tmovq -" + std::to_string(currentCFG->getOffset(args.at(1))) + "(%rbp), %rsi");
    }
    if (size > 2) {
        write("\tmovq -" + std::to_string(currentCFG->getOffset(args.at(2))) + "(%rbp), %rdx");
    }
    if (size > 3) {
        write("\tmovq -" + std::to_string(currentCFG->getOffset(args.at(3))) + "(%rbp), %rcx");
    }
    if (size > 4) {
        write("\tmovq -" + std::to_string(currentCFG->getOffset(args.at(4))) + "(%rbp), %r8");
    }
    if (size > 5) {
        write("\tmovq -" + std::to_string(currentCFG->getOffset(args.at(5))) + "(%rbp), %r9");
    }
    if (size > 6) {
        for (auto it = args.rbegin(); it != (args.rend() - 6); ++it) {
            write("\tpushq -" + std::to_string(currentCFG->getOffset((*it))) + "(%rsp)");
        }
    }

    write("\tcall " + instr->label);
    write("\tmovq %rax, -" + std::to_string(currentCFG->getOffset(instr->dest)) + "(%rbp)");
}

void X86_64::rmem(RMemInstr *instr) {
    write("\tmovq -" + std::to_string(currentCFG->getOffset(instr->var2)) + "(%rbp), %rax");
    write("\tmovq %rax, -" + std::to_string(currentCFG->getOffset(instr->var1)) + "(%rbp)");
}

void X86_64::wmem(WMemInstr *instr) {
    write("\tmovq -" + std::to_string(currentCFG->getOffset(instr->var2)) + "(%rbp), %rax");
    write("\tmovq %rax, -" + std::to_string(currentCFG->getOffset(instr->var1)) + "(%rbp)");
}

void X86_64::unaryop(UnaryOpInstr *instr) {

}

void X86_64::incr(IncrInstr *instr) {

    write("\tmovq -" + std::to_string(currentCFG->getOffset(instr->var1)) + "(%rbp), %rax");
    write("\tmovq -" + std::to_string(currentCFG->getOffset(instr->var1)) + "(%rbp), %rbx");
    switch (instr->type) {
        case IncrInstr::PLUS:
            write("\tincq %rbx");
            break;
        case IncrInstr::MINUS:
            write("\tdecq %rbx");
            break;
    }

    write("\tmovq %rbx, -" + std::to_string(currentCFG->getOffset(instr->var1)) + "(%rbp)");

    if (!instr->isPostfix) {
        write("\tmovq %rbx, %rax");
    }
}

void X86_64::instrDispacher(IRInstr *instr) {
    if (auto i = dynamic_cast<OpInstr *>(instr)) op(i);
    else if (auto i = dynamic_cast<LoadConstInstr *>(instr)) loadConst(i);
    else if (auto i = dynamic_cast<CallInstr *>(instr)) call(i);
    else if (auto i = dynamic_cast<RMemInstr *>(instr)) rmem(i);
    else if (auto i = dynamic_cast<WMemInstr *>(instr)) wmem(i);
    else if (auto i = dynamic_cast<UnaryOpInstr *>(instr)) unaryop(i);
    else if (auto i = dynamic_cast<IncrInstr *>(instr)) incr(i);
}


static char getExtFromType(Type type) {
    switch (type) {
        case VOID:
            // Not possible;
            return 0;
        case CHAR:
            return 'b';
        case INT32_T:
            return 'l';
        case INT64_T:
            return 'q';
    }
}

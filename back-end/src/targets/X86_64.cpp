#include <function/FunctionDefinition.h>
#include "X86_64.h"
#include <ir/instructions/UnaryOpInstr.h>
#include <ir/globals/GlobalDeclarationVar.h>
#include <ir/globals/GlobalDeclarationTab.h>
#include <typeHelper.h>

using std::string;
using std::map;

X86_64::X86_64(Config *config, IRStruct *irStruct) : BaseTarget(config, irStruct) {}

void X86_64::parse() {
    open();

    // First the file header
    write("\t.file \"" + conf->fileToCompile + "\"");

    for (auto &&global : irStruct->globals) {
        write("\t.globl " + global.first);
        write("\t.data");
        write("\t.align 8"); // FIXME Alignment ?
        write("\t.type " + global.first + ", @object");

        if (auto var = dynamic_cast<GlobalDeclarationVar *>(global.second)) {
            write("\t.size " + var->name + ", " + std::to_string(getTypeAllocationSize(var->type)));

            write(var->name + ":");
            write("\t.quad " + std::to_string(var->value));

        } else if (auto tab = dynamic_cast<GlobalDeclarationTab *>(global.second)) {
            write("\t.size " + tab->name + ", " + std::to_string(tab->size * getTypeAllocationSize(tab->type)));

            write(tab->name + ":");

            for (auto &&value : *tab->values) {
                write("\t.quad " + std::to_string(value));
            }

            if (tab->size > tab->values->size()) {
                write("\t.zero " +
                      std::to_string(getTypeAllocationSize(tab->type) *
                                     (tab->size - tab->values->size()))
                );
            }
        }
    }

    for (auto cfg : irStruct->cfgs) {
        currentCFG = cfg.second;

        write("\t.text");
        write("\t.globl " + cfg.first);
        write("\t.type " + cfg.first + ", @function");

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
    long size = args->size();

    if (size > 0) {
        write("\tmovq %rdi, " + getAsmForVar(args->at(0)->getName()));
    }
    if (size > 1) {
        write("\tmovq %rsi, " + getAsmForVar(args->at(1)->getName()));
    }
    if (size > 2) {
        write("\tmovq %rdx, " + getAsmForVar(args->at(2)->getName()));
    }
    if (size > 3) {
        write("\tmovq %rcx, " + getAsmForVar(args->at(3)->getName()));
    }
    if (size > 4) {
        write("\tmovq %r8, " + getAsmForVar(args->at(4)->getName()));
    }
    if (size > 5) {
        write("\tmovq %r9, " + getAsmForVar(args->at(5)->getName()));
    }
    if (size > 6) {
        // FIXME We should copy from the caller stack to our stack
        // Don't know how to get the caller offset
        for (auto it = args->begin() + 6; it != args->end(); ++it) {
            write("\tpopq " + getAsmForVar((*it)->getName()));
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
    write("\tmovq " + getAsmForVar(left) + ", %rax");
    write("\tmovq " + getAsmForVar(right) + ", %rbx");

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

    write("\tmovq %rax, " + getAsmForVar(dest));
}

void X86_64::loadConst(LoadConstInstr *instr) {
    write("\tmovq $" + std::to_string(instr->value) + ", %rax");
    write("\tmovq %rax, " + getAsmForVar(instr->var));
}

void X86_64::call(CallInstr *instr) {
    auto args = instr->arguments;
    long size = args.size();

    if (size > 0) {
        write("\tmovq " + getAsmForVar(args.at(0)) + ", %rdi");
    }
    if (size > 1) {
        write("\tmovq " + getAsmForVar(args.at(1)) + ", %rsi");
    }
    if (size > 2) {
        write("\tmovq " + getAsmForVar(args.at(2)) + ", %rdx");
    }
    if (size > 3) {
        write("\tmovq " + getAsmForVar(args.at(3)) + ", %rcx");
    }
    if (size > 4) {
        write("\tmovq " + getAsmForVar(args.at(4)) + ", %r8");
    }
    if (size > 5) {
        write("\tmovq " + getAsmForVar(args.at(5)) + ", %r9");
    }
    if (size > 6) {
        for (auto it = args.rbegin(); it != (args.rend() - 6); ++it) {
            write("\tpushq " + getAsmForVar((*it)));
        }
    }

    write("\tcall " + instr->label);
    write("\tmovq %rax, " + getAsmForVar(instr->dest));
}

void X86_64::rmem(RMemInstr *instr) {
    write("\tmovq " + getAsmForVar(instr->var2) + ", %rax");
    write("\tmovq %rax, " + getAsmForVar(instr->var1));
}

void X86_64::wmem(WMemInstr *instr) {
    write("\tmovq " + getAsmForVar(instr->var2) + ", %rax");
    write("\tmovq %rax, " + getAsmForVar(instr->var1));
}

void X86_64::unaryop(UnaryOpInstr *instr) {
    switch (instr->type) {
        case UnaryOpInstr::PLUS:
            write("\tmovq " + getAsmForVar(instr->var1) + ", %rax");
            write("\tmovq %rax, " + getAsmForVar(instr->var));
            break;
        case UnaryOpInstr::MINUS:
            write("\tmovq " + getAsmForVar(instr->var1) + ", %rax");
            write("\tnegq %rax");
            write("\tmovq %rax, " + getAsmForVar(instr->var));
            break;
        case UnaryOpInstr::NOT :
            write("\tmovq $0, %rax");
            write("\tmovq " + getAsmForVar(instr->var1) + ", %rbx");
            write("\tcmpq %rax, %rbx");
            write("\tmovq $1, %rbx");
            write("\tcmove %rbx, %rax");
            write("\tmovq %rax, " + getAsmForVar(instr->var));
            break;
        case UnaryOpInstr::BITWISE_NOT :
            write("\tmovq " + getAsmForVar(instr->var1) + ", %rax");
            write("\tnotq %rax");
            write("\tmovq %rax, " + getAsmForVar(instr->var));
            break;
    }
}

void X86_64::incr(IncrInstr *instr) {

    write("\tmovq " + getAsmForVar(instr->var1) + ", %rax");
    write("\tmovq " + getAsmForVar(instr->var1) + ", %rbx");
    switch (instr->type) {
        case IncrInstr::PLUS:
            write("\tincq %rbx");
            break;
        case IncrInstr::MINUS:
            write("\tdecq %rbx");
            break;
    }

    write("\tmovq %rbx, " + getAsmForVar(instr->var1));

    string reg = instr->isPostfix ? "%rax" : "%rbx";

    write("\tmovq " + reg + ", " + getAsmForVar(instr->var));

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

string X86_64::getAsmForVar(string var) {
    auto offset = currentCFG->getOffset(var);

    if (offset != -1) {
        return "-" + std::to_string(offset) + "(%rbp)";
    }
    return var + "(%rip)";
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

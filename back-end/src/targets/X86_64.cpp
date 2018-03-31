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

    for (auto &&cfg : cfgs) {
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

    system(("as -o " + conf->fileToCompile + ".o " + conf->fileToCompile + ".s").c_str());
    auto result = system(("gcc -static -o " + conf->fileToCompile + ".out " + conf->fileToCompile + ".o").c_str());

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
        /*for (auto it = args.begin() + 6; it != args.end(); ++it) {
            write("\tpop -" + std::to_string(currentCFG->getOffset((*it)->getName())) + "(%rsp)");
        }*/

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
        for (auto &&instr : bb->instrs) {
            instrDispacher(instr);
        }

        // Jump to somewhere

        // Last basic block
        // TODO Check for return value ? return value go to %rax
        if (bb->exitTrue == nullptr) {
            return;
        }

        // Unconditional jump
        if (bb->exitFalse == nullptr) {

        }
    }
}


void X86_64::op(OpInstr *instr) {

}

void X86_64::loadConst(LoadConstInstr *instr) {
    string ldCst = "\tmovq $" +
                   std::to_string(instr->value) +
                   ", -" +
                   std::to_string(currentCFG->getOffset(instr->var)) +
                   "(%rbp)";
    write(ldCst);
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
            write("\tpush -" + std::to_string(currentCFG->getOffset((*it))) + "(%rsp)");
        }
    }

    write("\tcall " + instr->label);
}

void X86_64::rmem(RMemInstr *instr) {

}

void X86_64::wmem(WMemInstr *instr) {

}

void X86_64::unaryop(UnaryOpInstr *instr) {

}

void X86_64::instrDispacher(IRInstr *instr) {
    if (auto i = dynamic_cast<OpInstr *>(instr)) op(i);
    else if (auto i = dynamic_cast<LoadConstInstr *>(instr)) loadConst(i);
    else if (auto i = dynamic_cast<CallInstr *>(instr)) call(i);
    else if (auto i = dynamic_cast<RMemInstr *>(instr)) rmem(i);
    else if (auto i = dynamic_cast<WMemInstr *>(instr)) wmem(i);
    else if (auto i = dynamic_cast<UnaryOpInstr *>(instr)) unaryop(i);
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
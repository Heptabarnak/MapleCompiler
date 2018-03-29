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

}

void X86_64::prologue() {

    write("\tpushq %rbp");
    write("\tmovq %rsp, %rbp");

    // Now we must add the correct size of variables

    long allocationSize = currentCFG->getAllocationSize();
    string subq = "\tsubq $" + std::to_string(allocationSize) + ", %rsp";

    write(subq);
    write("");
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

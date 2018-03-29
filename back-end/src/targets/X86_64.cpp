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

    int allocationSize = currentCFG->getAllocationSize();
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


}

void X86_64::op(OpInstr *instr) {

}

void X86_64::loadConst(LoadConstInstr *instr) {

}

void X86_64::call(CallInstr *instr) {

}

void X86_64::rmemarray(RMemArrayInstr *instr) {

}

void X86_64::rmem(RMemInstr *instr) {

}

void X86_64::wmem(WMemInstr *instr) {

}

void X86_64::unaryop(UnaryOpInstr *instr) {

}

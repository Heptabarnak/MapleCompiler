#include "X86_64.h"

using std::string;
using std::map;

X86_64::X86_64(const string &filename, map<string, CFG *> &cfgs) : BaseTarget(filename, cfgs) {}

void X86_64::parse() {
    for (auto &&cfg : cfgs) {
        currentCFG = cfg.second;

        prologue();

        parseBasicBlocks();

        epilogue();
    }
}

void X86_64::compile() {

}

void X86_64::prologue() {

}

void X86_64::epilogue() {

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

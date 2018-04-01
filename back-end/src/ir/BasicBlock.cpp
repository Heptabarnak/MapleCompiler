#include "BasicBlock.h"

using std::string;

BasicBlock::BasicBlock(CFG *cfg, string entry_label)
        : cfg(cfg), label(entry_label), exitFalse(nullptr), exitTrue(nullptr) {}

void BasicBlock::addIRInstr(IRInstr *instr) {
    instrs.push_back(instr);
}

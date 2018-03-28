#include "BasicBlock.h"

BasicBlock::BasicBlock(CFG *cfg, std::string entry_label) : cfg(cfg), label(entry_label) {}

void BasicBlock::addIRInstr(IRInstr *instr) {
    instrs.push_back(instr);
}

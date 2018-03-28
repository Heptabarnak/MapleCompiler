#ifndef MAPLECOMPILER_BASICBLOCK_H
#define MAPLECOMPILER_BASICBLOCK_H

#include <iostream>
#include <vector>
#include <string>

#include "CFG.h"
#include "IRInstr.h"

class CFG;

class IRInstr;

class BasicBlock {
public:
    BasicBlock(CFG *cfg, std::string entry_label);

    void addIRInstr(IRInstr *instr);

    // No encapsulation whatsoever here. Feel free to do better.
    BasicBlock *exitTrue;  /**< pointer to the next basic block, true branch. If nullptr, return from procedure */
    BasicBlock *exitFalse; /**< pointer to the next basic block, false branch. If null_ptr, the basic block ends with an unconditional jump */
    std::string label; /**< label of the BB, also will be the label in the generated code */
    CFG *cfg; /** < the CFG where this block belongs */
    std::vector<IRInstr *> instrs; /** < the instructions themselves. */
};


#endif //MAPLECOMPILER_BASICBLOCK_H

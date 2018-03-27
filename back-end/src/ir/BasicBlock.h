#ifndef MAPLECOMPILER_BASICBLOCK_H
#define MAPLECOMPILER_BASICBLOCK_H

#include <iostream>
#include <vector>
#include <string>

#include <token/Type.h>

#include "CFG.h"
#include "IRInstr.h"

class CFG;

class IRInstr;

class BasicBlock {
public:
    BasicBlock(CFG *cfg, std::string entry_label);

    void genAsm(std::ostream &o); /**< x86 assembly code generation for this basic block (very simple) */

    void addIRInstr(IRInstr instr);

    // No encapsulation whatsoever here. Feel free to do better.
    BasicBlock *exitTrue;  /**< pointer to the next basic block, true branch. If nullptr, return from procedure */
    BasicBlock *exitFalse; /**< pointer to the next basic block, false branch. If null_ptr, the basic block ends with an unconditional jump */
    string label; /**< label of the BB, also will be the label in the generated code */
    CFG *cfg; /** < the CFG where this block belongs */
    vector<IRInstr *> instrs; /** < the instructions themselves. */
protected:

};


#endif //MAPLECOMPILER_BASICBLOCK_H

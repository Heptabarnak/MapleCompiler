#ifndef MAPLECOMPILER_CFG_H
#define MAPLECOMPILER_CFG_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <symbol-table/SymbolTable.h>

#include "BasicBlock.h"
#include "IRInstr.h"

class BasicBlock;

class IRInstr;

class SymbolTable;

class CFG {
public:
    explicit CFG(SymbolTable *symbolTable);

    void addBB(BasicBlock *bb);

    void addIRInstr(IRInstr *instr);

    std::string createNewTmpVar(Type type);

    // basic block management
    std::string newBBName();

    BasicBlock *currentBB;

    BasicBlock *getRootBB();

protected:
    int nextBBNumber; /**< just for naming */

    SymbolTable *symbolTable;

    std::vector<BasicBlock *> bbs; /**< all the basic blocks of this CFG*/
};


#endif //MAPLECOMPILER_CFG_H

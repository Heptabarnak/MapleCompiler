#ifndef MAPLECOMPILER_CFG_H
#define MAPLECOMPILER_CFG_H

#include <vector>
#include <string>
#include <iostream>
#include <map>

#include <function/FunctionDefinition.h>

#include "BasicBlock.h"

class BasicBlock;

class CFG {
public:
    explicit CFG(SymbolTable *symbolTable);

    void addBB(BasicBlock *bb);

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

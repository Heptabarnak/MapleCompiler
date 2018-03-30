#ifndef MAPLECOMPILER_CFG_H
#define MAPLECOMPILER_CFG_H

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <token/Type.h>

#include "BasicBlock.h"
#include "IRInstr.h"

class BasicBlock;

class IRInstr;

class FunctionDefinition;

class CFG {
public:
    explicit CFG(FunctionDefinition *funcDef);

    void addBB(BasicBlock *bb);

    void addIRInstr(IRInstr *instr);

    std::string createNewTmpVar(Type type);

    // basic block management
    std::string newBBName();

    BasicBlock *currentBB;

    BasicBlock *getRootBB();

    long getAllocationSize();

    std::vector<BasicBlock *> &getBBs();

    long getOffset(std::string name);

    FunctionDefinition *getFunctionDefinition();

protected:
    int nextBBNumber; /**< just for naming */

    FunctionDefinition *funcDef;

    std::vector<BasicBlock *> bbs; /**< all the basic blocks of this CFG*/
};


#endif //MAPLECOMPILER_CFG_H

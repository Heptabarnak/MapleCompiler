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
    CFG(FunctionDefinition *ast);

    FunctionDefinition *ast; /**< The AST this CFG comes from */

    void addBB(BasicBlock *bb);

    std::string createNewTmpVar(Type type);

    // x86 code generation: could be encapsulated in a processor class in a retargetable compiler
    void genAsm(std::ostream &o);

    std::string IRRegToAsm(
            std::string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */

    void genAsmPrologue(std::ostream &o);

    void genAsmEpilogue(std::ostream &o);

    // symbol table methods
    void addToSymbolTable(std::string name, Type t);

    int getVarIndex(std::string name);

    Type getVarType(std::string name);

    // basic block management
    std::string newBBName();

    BasicBlock *currentBB;

protected:
    int nextBBnumber; /**< just for naming */

    std::vector<BasicBlock *> bbs; /**< all the basic blocks of this CFG*/
};


#endif //MAPLECOMPILER_CFG_H

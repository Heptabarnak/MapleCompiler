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

    // x86 code generation: could be encapsulated in a processor class in a retargetable compiler
    void genAsm(std::ostream &o);

    string IRRegToAsm(
            string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */

    void genAsmPrologue(std::ostream &o);

    void genAsmEpilogue(std::ostream &o);

    // symbol table methods
    void addToSymbolTable(string name, Type t);

    string createNewTmpVar(Type t);

    int getVarIndex(string name);

    Type getVarType(string name);

    // basic block management
    string newBBName();

    BasicBlock *currentBB;

protected:
    std::map<string, Type> symbolType; /**< part of the symbol table  */
    std::map<string, int> symbolIndex; /**< part of the symbol table  */
    int nextFreeSymbolIndex; /**< to allocate new symbols in the symbol table */
    int nextBBnumber; /**< just for naming */

    std::vector<BasicBlock *> bbs; /**< all the basic blocks of this CFG*/

};


#endif //MAPLECOMPILER_CFG_H

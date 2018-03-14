#ifndef ANTLR4CPP_FETCHER_BLOCKFUNCTION_H
#define ANTLR4CPP_FETCHER_BLOCKFUNCTION_H


#include <list>
#include <declaration/Declaration.h>
#include <control-structure/Instruction.h>
#include <symbol-table/SymbolTable.h>

using std::list;

class BlockFunction {

private:
    list<Declaration *> declarations;
    list<Instruction *> instructions;
    SymbolTable *symbolTable;

public:
    BlockFunction(const list<Declaration *> &declarations, const list<Instruction *> &instructions,
                  SymbolTable *symbolTable);

};


#endif //ANTLR4CPP_FETCHER_BLOCKFUNCTION_H

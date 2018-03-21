#ifndef ANTLR4CPP_FETCHER_SYMBOL_H
#define ANTLR4CPP_FETCHER_SYMBOL_H

#include "SymbolTable.h"
#include "declaration/Declaration.h"

class SymbolTable;

class Symbol {
public:
    Symbol(SymbolTable* table);
    ~Symbol();
    Declaration declaration;
    bool affectation;
private:
    SymbolTable* table;
};


#endif //ANTLR4CPP_FETCHER_SYMBOL_H

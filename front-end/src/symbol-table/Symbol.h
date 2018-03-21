#ifndef ANTLR4CPP_FETCHER_SYMBOL_H
#define ANTLR4CPP_FETCHER_SYMBOL_H

#include "SymbolTable.h"
#include "declaration/Declaration.h"

class SymbolTable;

class Symbol {
public:
    Symbol(SymbolTable* table, bool aff, bool r);
    ~Symbol();
    Declaration declaration;
    bool affectation;
private:
    SymbolTable* table;
    bool affectation;
    bool read;
};


#endif //ANTLR4CPP_FETCHER_SYMBOL_H

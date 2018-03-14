#ifndef ANTLR4CPP_FETCHER_SYMBOL_H
#define ANTLR4CPP_FETCHER_SYMBOL_H

#include "SymbolTable.h"

class SymbolTable;

class Symbol {
public:
    Symbol(SymbolTable* table);
    ~Symbol();
private:
    SymbolTable* table;
};


#endif //ANTLR4CPP_FETCHER_SYMBOL_H

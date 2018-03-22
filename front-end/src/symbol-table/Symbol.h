#ifndef MAPLECOMPILER_SYMBOL_H
#define MAPLECOMPILER_SYMBOL_H

#include "SymbolTable.h"
#include "declaration/Declaration.h"

class SymbolTable;

class Symbol {
public:
    Symbol(SymbolTable* table, Declaration * dec, bool aff = false, bool r = false);
    ~Symbol();

    Declaration *getDeclaration() const;

private:
    SymbolTable* table;
    Declaration* declaration;
    bool affectation;
    bool read;
};


#endif //MAPLECOMPILER_SYMBOL_H

#ifndef MAPLECOMPILER_SYMBOL_H
#define MAPLECOMPILER_SYMBOL_H

#include "SymbolTable.h"

class SymbolTable;

class Declaration;

class Symbol {
public:
    Symbol(SymbolTable *table, Declaration *dec, bool aff = false, bool r = false);

    ~Symbol();

    Declaration *getDeclaration() const;

    bool getRead();

    bool getAffectation();

    void doRead();

    void doAffectation();

private:
    SymbolTable *table;
    Declaration *declaration;
    bool affectation;
    bool read;

};


#endif //MAPLECOMPILER_SYMBOL_H

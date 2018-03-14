#ifndef ANTLR4CPP_FETCHER_SYMBOLE_H
#define ANTLR4CPP_FETCHER_SYMBOLE_H

#include "SymboleTable.h"

class SymboleTable;

class Symbole {
public:
    Symbole(SymboleTable* table);
    ~Symbole();
private:
    SymboleTable* table;
};


#endif //ANTLR4CPP_FETCHER_SYMBOLE_H

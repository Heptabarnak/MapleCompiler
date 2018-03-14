#ifndef ANTLR4CPP_FETCHER_SYMBOLETABLE_H
#define ANTLR4CPP_FETCHER_SYMBOLETABLE_H

#include <unordered_map>
#include <string>
#include <list>
#include "Symbole.h"

using std::unordered_map;
using std::string;
using std::list;

class Symbole;


class SymboleTable {
public:
    SymboleTable();
    ~SymboleTable();

private:
    unordered_map<string, Symbole*> symbols;
    SymboleTable* father;
    list<SymboleTable*> children;
};


#endif //ANTLR4CPP_FETCHER_SYMBOLETABLE_H

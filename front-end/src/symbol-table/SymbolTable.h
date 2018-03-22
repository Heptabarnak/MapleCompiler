#ifndef MAPLECOMPILER_SYMBOLTABLE_H
#define MAPLECOMPILER_SYMBOLTABLE_H

#include <map>
#include <string>
#include <vector>
#include "Symbol.h"

using std::map;
using std::string;
using std::vector;

class Symbol;


class SymbolTable {
public:
    explicit SymbolTable(SymbolTable *father = nullptr);

    ~SymbolTable();

    SymbolTable *insert(string name, Symbol *symbol);

    Symbol *lookup(string name);

    SymbolTable *getFather();

private:
    map<string, Symbol *> symbols;
    SymbolTable *father;
    vector<SymbolTable *> children;
};


#endif //MAPLECOMPILER_SYMBOLTABLE_H

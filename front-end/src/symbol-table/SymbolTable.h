#ifndef ANTLR4CPP_FETCHER_SYMBOLTABLE_H
#define ANTLR4CPP_FETCHER_SYMBOLTABLE_H

#include <unordered_map>
#include <string>
#include <list>
#include "Symbol.h"

using std::unordered_map;
using std::string;
using std::list;

class Symbol;


class SymbolTable {
public:
    SymbolTable(SymbolTable* father = nullptr);
    ~SymbolTable();
    SymbolTable* insert(string name, Symbol* symbol);
    Symbol* lookup(string name);

private:
    unordered_map<string, Symbol*> symbols;
    SymbolTable* father;
    list<SymbolTable*> children;
};


#endif //ANTLR4CPP_FETCHER_SYMBOLTABLE_H

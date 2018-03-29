#ifndef MAPLECOMPILER_SYMBOLTABLE_H
#define MAPLECOMPILER_SYMBOLTABLE_H

#include <map>
#include <string>
#include <vector>
#include <token/Type.h>
#include "Symbol.h"

class Symbol;


class SymbolTable {
public:
    explicit SymbolTable(SymbolTable *father = nullptr);

    ~SymbolTable();

    SymbolTable *insert(std::string name, Symbol *symbol);

    Symbol *lookup(std::string name);

    void staticAnalysis();

    SymbolTable *getFather();

    std::string createNewTmpVar(Type type);

    int getAllocationSize();

private:
    std::map<std::string, Symbol *> symbols;

    std::map<int, std::string> levels;
    int lastLevel = 0;

    SymbolTable *father;
    std::vector<SymbolTable *> children;
};


#endif //MAPLECOMPILER_SYMBOLTABLE_H

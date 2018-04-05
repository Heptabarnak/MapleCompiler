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

    long getOffset(std::string &name);

    long getAllocationSize();

    void sortByType();

private:
    std::map<std::string, Symbol *> symbols;
    std::map<int, std::string> levels;
    int order = 0;

    std::map<std::string, long> offsetTable;
    long offset = 8; // Start at 8 for %rbp

    SymbolTable *father;
    std::vector<SymbolTable *> children;
};


#endif //MAPLECOMPILER_SYMBOLTABLE_H

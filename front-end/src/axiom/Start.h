#ifndef MAPLECOMPILER_START_H
#define MAPLECOMPILER_START_H


#include <vector>
#include <symbol-table/SymbolTable.h>
#include <declaration/Declaration.h>

class Start {

protected:
    std::vector<Declaration *> declarations;
    SymbolTable *globalSymbolTable;
public:
    SymbolTable *getGlobalSymbolTable() const;

    const std::vector<Declaration *> &getDeclarations() const;

    Start(const std::vector<Declaration *> &declarations, SymbolTable *globalSymbolTable);
};


#endif //MAPLECOMPILER_START_H

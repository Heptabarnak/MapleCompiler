#ifndef MAPLECOMPILER_START_H
#define MAPLECOMPILER_START_H


#include <vector>
#include <symbol-table/SymbolTable.h>
#include <declaration/Declaration.h>

using std::vector;

class Start {

protected:
    vector<Declaration *> declarations;
    SymbolTable *globalSymbolTable;

public:
    Start(const vector<Declaration *> &declarations, SymbolTable *globalSymbolTable);

};


#endif //MAPLECOMPILER_START_H

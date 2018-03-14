

#ifndef MAPLECOMPILER_START_H
#define MAPLECOMPILER_START_H


#include <list>
#include <symbole-table/SymboleTable.h>

class start {

protected:
    std::list<Program> programs;
    SymboleTable globalSymbolTable;

};


#endif //MAPLECOMPILER_START_H



#ifndef MAPLECOMPILER_START_H
#define MAPLECOMPILER_START_H


#include <list>
#include <symbol-table/SymbolTable.h>

class start {

protected:
    std::list<Program> programs;
    SymbolTable globalSymbolTable;

};


#endif //MAPLECOMPILER_START_H

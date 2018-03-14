#ifndef MAPLECOMPILER_START_H
#define MAPLECOMPILER_START_H


#include <list>
#include <symbol-table/SymbolTable.h>
#include <declaration/Declaration.h>

using std::list;

class Start {

protected:
    list<Declaration *> declarations;
    SymbolTable globalSymbolTable;

};


#endif //MAPLECOMPILER_START_H

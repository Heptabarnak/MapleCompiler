#ifndef ANTLR4CPP_FETCHER_TABDECLARATION_H
#define ANTLR4CPP_FETCHER_TABDECLARATION_H

#include <token/Type.h>
#include <expressions/Value.h>
#include <list>


using std::list;

class TabDeclaration {

protected:
    Type type;
    list<Value> definition;

};


#endif //ANTLR4CPP_FETCHER_TABDECLARATION_H

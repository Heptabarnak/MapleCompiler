#ifndef ANTLR4CPP_FETCHER_TABDECLARATION_H
#define ANTLR4CPP_FETCHER_TABDECLARATION_H

#include <token/Type.h>
#include <expression/Value.h>
#include <list>
#include <string>


using std::list;
using std::string;

class TabDeclaration {

private:
    Type type;
    string name;
    int size;
    list<Value *> definition;

public:
    TabDeclaration(Type type, const string &name, int size, const list<Value *> &definition);

};


#endif //ANTLR4CPP_FETCHER_TABDECLARATION_H

#ifndef ANTLR4CPP_FETCHER_VARDECLARATION_H
#define ANTLR4CPP_FETCHER_VARDECLARATION_H

#include <list>
#include <string>
#include <expression/Expr.h>
#include <token/Type.h>

using std::string;

class VarDeclaration {

private:
    string name;
    Type type;
    Expr *assignment;

public:
    VarDeclaration(const string &name, Type type, Expr *assignment);

};


#endif //ANTLR4CPP_FETCHER_VARDECLARATION_H

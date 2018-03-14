#ifndef ANTLR4CPP_FETCHER_VARDECLARATION_H
#define ANTLR4CPP_FETCHER_VARDECLARATION_H

#include <list>
#include <string>
#include <expressions/Expr.h>

using std::string;

#include <expressions/Expr.h>

class VarDeclaration {

protected:
    string name;
    Expr Assignment;

};


#endif //ANTLR4CPP_FETCHER_VARDECLARATION_H

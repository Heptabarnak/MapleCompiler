//
// Created by loicsrz on 14/03/2018.
//

#ifndef ANTLR4CPP_FETCHER_VARDECLARATION_H
#define ANTLR4CPP_FETCHER_VARDECLARATION_H

#include <list>
#include <string>
#include <expressions/Expr.h>

using std::string;

class VarDeclaration {

protected:
    string name;
    Expr Assignment;

};


#endif //ANTLR4CPP_FETCHER_VARDECLARATION_H

//
// Created by loicsrz on 14/03/2018.
//

#ifndef ANTLR4CPP_FETCHER_VARDECLARATION_H
#define ANTLR4CPP_FETCHER_VARDECLARATION_H


#include <expressions/Expr.h>

class VarDeclaration {

protected:
    std::list<Var> variables;
    Expr Assignment;

};


#endif //ANTLR4CPP_FETCHER_VARDECLARATION_H

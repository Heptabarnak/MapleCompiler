#ifndef ANTLR4CPP_FETCHER_EXPROPERATION_H
#define ANTLR4CPP_FETCHER_EXPROPERATION_H

#include <expression/Expr.h>

class ExprOperation : public Expr {
protected:
    Expr *leftExpr;
    Expr *rightExpr;

protected:
    ExprOperation(Expr *left, Expr *right) : leftExpr(left), rightExpr(right) {}

};


#endif //ANTLR4CPP_FETCHER_EXPROPERATION_H

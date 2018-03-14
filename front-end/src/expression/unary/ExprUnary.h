#ifndef ANTLR4CPP_FETCHER_EXPRUNARY_H
#define ANTLR4CPP_FETCHER_EXPRUNARY_H

#include <expression/Expr.h>

class ExprUnary : public Expr {
protected:
    Expr *expr;

    ExprUnary(Expr *expr) : expr(expr) {}
};


#endif //ANTLR4CPP_FETCHER_EXPRUNARY_H

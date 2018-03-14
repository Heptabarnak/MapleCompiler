#ifndef ANTLR4CPP_FETCHER_EXPRPARENTHESIS_H
#define ANTLR4CPP_FETCHER_EXPRPARENTHESIS_H


#include "Expr.h"

class ExprParenthesis : public Expr {

private:
    Expr *expr;

public:
    ExprParenthesis(Expr *expr);
};


#endif //ANTLR4CPP_FETCHER_EXPRPARENTHESIS_H

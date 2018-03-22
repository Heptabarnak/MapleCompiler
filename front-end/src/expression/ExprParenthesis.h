#ifndef MAPLECOMPILER_EXPRPARENTHESIS_H
#define MAPLECOMPILER_EXPRPARENTHESIS_H


#include "Expr.h"

class ExprParenthesis : public Expr {

private:
    Expr *expr;

public:
    ExprParenthesis(Expr *expr);

    bool isSimplifiable() override;

    long simplify() override;
};


#endif //MAPLECOMPILER_EXPRPARENTHESIS_H

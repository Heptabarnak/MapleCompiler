#ifndef MAPLECOMPILER_EXPRPARENTHESIS_H
#define MAPLECOMPILER_EXPRPARENTHESIS_H


#include "Expr.h"
#include <string>

class ExprParenthesis : public Expr {

private:
    Expr *expr;

public:
    ExprParenthesis(Expr *expr);

    bool isSimplifiable() override;

    long simplify() override;

    std::string ExprParenthesis::buildIR(CFG *cfg);
};


#endif //MAPLECOMPILER_EXPRPARENTHESIS_H

#ifndef MAPLECOMPILER_EXPRPARENTHESIS_H
#define MAPLECOMPILER_EXPRPARENTHESIS_H


#include "Expr.h"
#include <string>

class ExprParenthesis : public Expr {

private:
    Expr *expr;

public:
    explicit ExprParenthesis(Expr *expr);

    bool isSimplifiable() override;

    long simplify() override;

    std::string buildIR(CFG *cfg);
};


#endif //MAPLECOMPILER_EXPRPARENTHESIS_H

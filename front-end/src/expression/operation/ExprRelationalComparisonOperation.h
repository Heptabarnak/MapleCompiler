#ifndef MAPLECOMPILER_EXPRRELATIONALCOMPARISONOPERATION_H
#define MAPLECOMPILER_EXPRRELATIONALCOMPARISONOPERATION_H

#include <string>
#include "ExprOperation.h"

class ExprRelationalComparisonOperation : public ExprOperation {
private:
    enum RelationalComparisonOperation {
        LESS,
        LESS_EQUAL,
        MORE,
        MORE_EQUAL
    };

    RelationalComparisonOperation operation;

public:
    ExprRelationalComparisonOperation(Expr *left, Expr *right, const std::string &op);

    std::string buildIR(CFG *cfg) override;

    long simplify() override;
};


#endif //MAPLECOMPILER_EXPRRELATIONALCOMPARISONOPERATION_H

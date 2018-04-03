#ifndef MAPLECOMPILER_EXPREQUALITYCOMPARISONOPERATION_H
#define MAPLECOMPILER_EXPREQUALITYCOMPARISONOPERATION_H

#include <string>
#include "ExprOperation.h"

class ExprEqualityComparisonOperation : public ExprOperation {
private:
    enum EqualityComparisonOperation {
        EQUAL,
        NOT_EQUAL
    };

    EqualityComparisonOperation operation;

public:
    ExprEqualityComparisonOperation(Expr *left, Expr *right, const std::string &op);

    std::string buildIR(CFG *cfg);

    long simplify() override;
};


#endif //MAPLECOMPILER_EXPREQUALITYCOMPARISONOPERATION_H

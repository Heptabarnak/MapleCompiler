#ifndef MAPLECOMPILER_EXPREQUALITYCOMPARISONOPERATION_H
#define MAPLECOMPILER_EXPREQUALITYCOMPARISONOPERATION_H

#include <string>
#include "ExprOperation.h"

using std::string;

class ExprEqualityComparisonOperation : public ExprOperation {
private:
    enum EqualityComparisonOperation {
        EQUAL,
        NOT_EQUAL
    };

    EqualityComparisonOperation operation;

public:
    ExprEqualityComparisonOperation(Expr *left, Expr *right, const string &op);

    string buildIR(CFG *cfg) override;

    long simplify() override;
};


#endif //MAPLECOMPILER_EXPREQUALITYCOMPARISONOPERATION_H

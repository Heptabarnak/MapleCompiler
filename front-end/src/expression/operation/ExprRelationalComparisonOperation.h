#ifndef ANTLR4CPP_FETCHER_EXPRRELATIONALCOMPARISONOPERATION_H
#define ANTLR4CPP_FETCHER_EXPRRELATIONALCOMPARISONOPERATION_H

#include <string>
#include "ExprOperation.h"

using std::string;

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
    ExprRelationalComparisonOperation(Expr *left, Expr *right, const string &op);
};


#endif //ANTLR4CPP_FETCHER_EXPRRELATIONALCOMPARISONOPERATION_H

#ifndef ANTLR4CPP_FETCHER_EXPREQUALITYCOMPARISONOPERATION_H
#define ANTLR4CPP_FETCHER_EXPREQUALITYCOMPARISONOPERATION_H

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
};


#endif //ANTLR4CPP_FETCHER_EXPREQUALITYCOMPARISONOPERATION_H

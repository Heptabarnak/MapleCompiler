#ifndef ANTLR4CPP_FETCHER_EXPRADDITIVEOPERATION_H
#define ANTLR4CPP_FETCHER_EXPRADDITIVEOPERATION_H

#include <string>
#include "ExprOperation.h"

using std::string;

class ExprAdditiveOperation : public ExprOperation {
private:
    enum AdditiveOperation {
        PLUS,
        MINUS
    };

    AdditiveOperation operation;

public:
    ExprAdditiveOperation(Expr *left, Expr *right, const string &op);

};


#endif //ANTLR4CPP_FETCHER_EXPRADDITIVEOPERATION_H

#ifndef MAPLECOMPILER_EXPRADDITIVEOPERATION_H
#define MAPLECOMPILER_EXPRADDITIVEOPERATION_H

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

    long simplify() override;

};


#endif //MAPLECOMPILER_EXPRADDITIVEOPERATION_H

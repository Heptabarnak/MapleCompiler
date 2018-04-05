#ifndef MAPLECOMPILER_EXPRADDITIVEOPERATION_H
#define MAPLECOMPILER_EXPRADDITIVEOPERATION_H

#include <string>
#include "ExprOperation.h"

class ExprAdditiveOperation : public ExprOperation {
private:
    enum AdditiveOperation {
        PLUS,
        MINUS
    };

    AdditiveOperation operation;

public:
    ExprAdditiveOperation(Expr *left, Expr *right, const std::string &op, Type type);

    long simplify() override;

    std::string buildIR(CFG *cfg);
};


#endif //MAPLECOMPILER_EXPRADDITIVEOPERATION_H

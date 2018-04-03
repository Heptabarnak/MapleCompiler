//
// Created by Ordinateur on 03/04/2018.
//

#include "ExprCommaOperation.h"

ExprCommaOperation::ExprCommaOperation(Expr *left, Expr *right) : ExprOperation(left, right) {}

std::string ExprCommaOperation::buildIR(CFG *cfg) {
    std::string var1 = leftExpr->buildIR(cfg);
    std::string var2 = rightExpr->buildIR(cfg);

    return var2;
}

bool ExprCommaOperation::isSimplifiable() {
    return leftExpr->isSimplifiable() && rightExpr->isSimplifiable();
}

long ExprCommaOperation::simplify() {
    return rightExpr->simplify();
}

#include "ExprAndOperation.h"

ExprAndOperation::ExprAndOperation(Expr *left, Expr *right) : ExprOperation(left, right) {

}

long ExprAndOperation::simplify() {
    return leftExpr->simplify() && rightExpr->simplify();
}

std::string ExprAndOperation::buildIR(CFG *cfg) {

    // TODO If statement
    std::string var1 = leftExpr->buildIR(cfg);
    std::string var2 = rightExpr->buildIR(cfg);
}

#include "ExprBinaryOrOperation.h"


ExprBinaryOrOperation::ExprBinaryOrOperation(Expr *left, Expr *right) : ExprBinaryOperation(left, right) {

}

long ExprBinaryOrOperation::simplify() {
    return leftExpr->simplify() | rightExpr->simplify();
}

string ExprBinaryOrOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);
    string var3 = cfg->createNewTmpVar();
    // TODO : Create instruction for binary or
    return var3;
}

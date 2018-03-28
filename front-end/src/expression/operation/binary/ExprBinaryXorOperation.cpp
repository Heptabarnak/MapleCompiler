#include "ExprBinaryXorOperation.h"

ExprBinaryXorOperation::ExprBinaryXorOperation(Expr *left, Expr *right) : ExprBinaryOperation(left, right) {

}

long ExprBinaryXorOperation::simplify() {
    return leftExpr->simplify() ^ rightExpr->simplify();
}

string ExprBinaryXorOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);
    string var3 = cfg->createNewTmpVar();
    // TODO : Create instruction for binary xor
    return var3;
}

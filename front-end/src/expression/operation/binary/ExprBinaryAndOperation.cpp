#include "ExprBinaryAndOperation.h"

ExprBinaryAndOperation::ExprBinaryAndOperation(Expr *left, Expr *right) : ExprBinaryOperation(left, right) {

}

long ExprBinaryAndOperation::simplify() {
    return leftExpr->simplify() & rightExpr->simplify();
}

string ExprBinaryAndOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);
    string var3 = cfg->createNewTmpVar();
    // TODO : Create instruction for binary and
    cfg->currentBB->addIRInstr(new IRInstr(cfg->currentBB, INT64_T));
    return var3;
}

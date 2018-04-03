#include <ir/instructions/OpInstr.h>
#include "ExprBinaryAndOperation.h"

using std::string;

ExprBinaryAndOperation::ExprBinaryAndOperation(Expr *left, Expr *right) : ExprBinaryOperation(left, right) {

}

long ExprBinaryAndOperation::simplify() {
    return leftExpr->simplify() & rightExpr->simplify();
}

string ExprBinaryAndOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);
    string var = cfg->createNewTmpVar(INT64_T);

    cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::AND, var, var1, var2));
    return var;
}

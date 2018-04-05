#include <ir/instructions/OpInstr.h>
#include "ExprBinaryOrOperation.h"

using std::string;

ExprBinaryOrOperation::ExprBinaryOrOperation(Expr *left, Expr *right, Type type) : ExprBinaryOperation(left, right, type) {

}

long ExprBinaryOrOperation::simplify() {
    return leftExpr->simplify() | rightExpr->simplify();
}

string ExprBinaryOrOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);
    string var = cfg->createNewTmpVar(getType());

    cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::OR, var, var1, var2, getType(), leftExpr->getType(), rightExpr->getType()));
    return var;
}

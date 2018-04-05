#include <ir/instructions/OpInstr.h>
#include "ExprBinaryOrOperation.h"

using std::string;

ExprBinaryOrOperation::ExprBinaryOrOperation(Expr *left, Expr *right) : ExprBinaryOperation(left, right) {

}

long ExprBinaryOrOperation::simplify() {
    return leftExpr->simplify() | rightExpr->simplify();
}

string ExprBinaryOrOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);
    string var = cfg->createNewTmpVar(INT64_T);

    cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::OR, var, var1, var2, INT64_T));
    return var;
}

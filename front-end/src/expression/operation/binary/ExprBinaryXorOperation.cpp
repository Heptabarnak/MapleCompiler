#include <ir/instructions/OpInstr.h>
#include "ExprBinaryXorOperation.h"

using std::string;

ExprBinaryXorOperation::ExprBinaryXorOperation(Expr *left, Expr *right) : ExprBinaryOperation(left, right) {

}

long ExprBinaryXorOperation::simplify() {
    return leftExpr->simplify() ^ rightExpr->simplify();
}

string ExprBinaryXorOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);
    string var = cfg->createNewTmpVar(INT64_T);

    cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::XOR, var, var1, var2));
    return var;
}

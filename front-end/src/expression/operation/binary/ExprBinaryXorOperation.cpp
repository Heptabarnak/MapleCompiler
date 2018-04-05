#include <ir/instructions/OpInstr.h>
#include "ExprBinaryXorOperation.h"

using std::string;

ExprBinaryXorOperation::ExprBinaryXorOperation(Expr *left, Expr *right, Type type) : ExprBinaryOperation(left, right, type) {

}

long ExprBinaryXorOperation::simplify() {
    return leftExpr->simplify() ^ rightExpr->simplify();
}

string ExprBinaryXorOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);
    string var = cfg->createNewTmpVar(getType());

    cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::XOR, var, var1, var2, getType(), leftExpr->getType(), rightExpr->getType()));
    return var;
}

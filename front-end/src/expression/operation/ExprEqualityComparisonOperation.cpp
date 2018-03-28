#include <str2int.h>
#include <ir/instructions/CmpEqInstr.h>
#include "ExprEqualityComparisonOperation.h"

ExprEqualityComparisonOperation::ExprEqualityComparisonOperation(Expr *left, Expr *right, const string &op)
        : ExprOperation(left, right) {

    switch (str2int(op.c_str())) {
        case str2int("=="):
            operation = EQUAL;
            break;
        case str2int("!="):
            operation = NOT_EQUAL;
            break;
        default:
            // TODO Throw ERROR
            break;
    }
}

long ExprEqualityComparisonOperation::simplify() {
    switch (operation) {
        case EQUAL:
            return leftExpr->simplify() == rightExpr->simplify();
        case NOT_EQUAL:
            return leftExpr->simplify() != rightExpr->simplify();
    }
}

string ExprEqualityComparisonOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = leftExpr->buildIR(cfg);
    string var3 = cfg->createNewTmpVar(INT64_T);
    cfg->currentBB->addIRInstr(new CmpEqInstr(cfg->currentBB, INT64_T));
    return var3;
}

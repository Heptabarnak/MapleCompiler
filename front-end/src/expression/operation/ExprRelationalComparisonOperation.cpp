#include <str2int.h>
#include "ExprRelationalComparisonOperation.h"

ExprRelationalComparisonOperation::ExprRelationalComparisonOperation(Expr *left, Expr *right, const string &op)
        : ExprOperation(left, right) {

    switch (str2int(op.c_str())) {
        case str2int("<"):
            operation = LESS;
            break;
        case str2int("<="):
            operation = LESS_EQUAL;
            break;
        case str2int(">"):
            operation = MORE;
            break;
        case str2int(">="):
            operation = MORE_EQUAL;
            break;
        default:
            // TODO Throw ERROR
            break;
    }
}

long ExprRelationalComparisonOperation::simplify() {

    switch (operation) {
        case LESS:
            return leftExpr->simplify() < rightExpr->simplify();
        case LESS_EQUAL:
            return leftExpr->simplify() <= rightExpr->simplify();
        case MORE:
            return leftExpr->simplify() > rightExpr->simplify();
        case MORE_EQUAL:
            return leftExpr->simplify() >= rightExpr->simplify();
    }
}

string ExprRelationalComparisonOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);
    string var3 = cfg->createNewTmpVar(INT64_T);
    //TODO create CmpRelInstr class
    cfg->currentBB->addIRInstr(new CmpRelInstr(cfg->currentBB, INT64_T));
}

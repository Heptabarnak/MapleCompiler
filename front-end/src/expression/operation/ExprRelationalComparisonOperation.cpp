#include <str2int.h>
#include <ir/instructions/OpInstr.h>
#include <ir/instructions/UnaryOpInstr.h>
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

    bool mustBeInverted = false;
    OpInstr::OpType type = OpInstr::LESS_THAN;
    switch (operation) {
        case LESS_EQUAL:
            type = OpInstr::LESS_THAN_OR_EQ;
            break;
        case MORE:
            mustBeInverted = true;
            type = OpInstr::LESS_THAN_OR_EQ;
            break;
        case MORE_EQUAL:
            mustBeInverted = true;
            type = OpInstr::LESS_THAN;
            break;
    }

    string var = cfg->createNewTmpVar(INT64_T);
    cfg->addIRInstr(new OpInstr(cfg->currentBB, type, var, var1, var2));

    if (!mustBeInverted) {
        return var;
    }

    auto notVar = cfg->createNewTmpVar(Type::INT64_T);
    cfg->addIRInstr(new UnaryOpInstr(cfg->currentBB, UnaryOpInstr::NOT, notVar, var));

    return notVar;
}

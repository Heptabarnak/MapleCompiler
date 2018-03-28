#include <str2int.h>
#include <ir/instructions/OpInstr.h>
#include <ostream>
#include "ExprBinaryShiftOperation.h"

using namespace std;

ExprBinaryShiftOperation::ExprBinaryShiftOperation(Expr *left, Expr *right, const string &op)
        : ExprBinaryOperation(left, right) {

    switch (str2int(op.c_str())) {
        case str2int("<<"):
            operation = LEFT;
            break;
        case str2int(">>"):
            operation = RIGHT;
            break;
        default:
            cerr << "Operator expected to be \"<<\" or \">>\" but did not match." << endl;
            break;
    }
}

long ExprBinaryShiftOperation::simplify() {
    switch (operation) {
        case RIGHT:
            return leftExpr->simplify() >> rightExpr->simplify();
        case LEFT:
            return leftExpr->simplify() << rightExpr->simplify();
    }
}

string ExprBinaryShiftOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);
    string var = cfg->createNewTmpVar(INT64_T);

    OpInstr::OpType type = OpInstr::SHIFT_LEFT;

    switch (operation) {
        case RIGHT:
            type = OpInstr::SHIFT_RIGHT;
            break;
    }

    cfg->addIRInstr(new OpInstr(cfg->currentBB, type, var, var1, var2));
    return var;
}

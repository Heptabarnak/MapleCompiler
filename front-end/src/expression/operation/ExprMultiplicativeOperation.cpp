#include <str2int.h>
#include <iostream>
#include <stdexcept>
#include <ir/instructions/OpInstr.h>
#include "ExprMultiplicativeOperation.h"

using std::cerr;
using std::endl;
using std::string;

ExprMultiplicativeOperation::ExprMultiplicativeOperation(Expr *left, Expr *right, const string &op, Type type)
        : ExprOperation(left, right, type) {

    switch (str2int(op.c_str())) {
        case str2int("*"):
            operation = MULT;
            break;
        case str2int("/"):
            operation = DIV;
            break;
        case str2int("%"):
            operation = MOD;
            break;
        default:
            cerr << "Operator expected to be \"*\", \"/\" or \"%\" but did not match." << endl;
            throw std::runtime_error("[ExprMultiplicativeOperation] Unexpected operator");
    }
}

long ExprMultiplicativeOperation::simplify() {
    switch (operation) {
        case MULT:
            return leftExpr->simplify() * rightExpr->simplify();
        case DIV:
            if (rightExpr->simplify() != 0) {
                return leftExpr->simplify() / rightExpr->simplify();
            } else {
                cerr << "Division by 0 is forbidden" << endl;
                throw std::runtime_error("Forbidden operation : division by zero");
            }
        case MOD:
            return leftExpr->simplify() % rightExpr->simplify();
    }
}

string ExprMultiplicativeOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);
    string var = cfg->createNewTmpVar(INT64_T);

    OpInstr::OpType type = OpInstr::MULT;

    switch (operation) {
        case DIV:
            type = OpInstr::DIV;
            break;
        case MOD:
            type = OpInstr::MOD;
            break;
    }

    cfg->addIRInstr(new OpInstr(cfg->currentBB, type, var, var1, var2, INT64_T));
    return var;
}

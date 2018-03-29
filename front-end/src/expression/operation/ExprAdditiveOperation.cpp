#include <str2int.h>
#include <ir/instructions/OpInstr.h>
#include <ostream>
#include "ExprAdditiveOperation.h"

using std::cerr;
using std::endl;
using std::string;


ExprAdditiveOperation::ExprAdditiveOperation(Expr *left, Expr *right, const string &op) : ExprOperation(left, right) {

    switch (str2int(op.c_str())) {
        case str2int("+"):
            operation = PLUS;
            break;
        case str2int("-"):
            operation = MINUS;
            break;
        default:
            cerr << "Operator expected to be \"+\" or \"-\" but did not match." << endl;
            break;
    }
}

long ExprAdditiveOperation::simplify() {
    switch (operation) {
        case PLUS:
            return leftExpr->simplify() + rightExpr->simplify();
        case MINUS:
            return leftExpr->simplify() - rightExpr->simplify();
    }
}

string ExprAdditiveOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);
    string var = cfg->createNewTmpVar(INT64_T);

    OpInstr::OpType type = OpInstr::ADD;
    switch (operation) {
        case MINUS:
            type = OpInstr::SUB;
            break;
    }

    cfg->addIRInstr(new OpInstr(cfg->currentBB, type, var, var1, var2));
    return var;
}

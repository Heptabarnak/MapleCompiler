#include <str2int.h>
#include <ir/instructions/OpInstr.h>
#include <ir/instructions/UnaryOpInstr.h>
#include <ostream>
#include <stdexcept>
#include "ExprEqualityComparisonOperation.h"

using std::cerr;
using std::endl;
using std::string;


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
            cerr << "Operator expected to be \"==\" or \"!=\" but did not match." << endl;
            throw std::runtime_error("[ExprEqualityComparisonOperation] Unexpected operator");
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
    string var2 = rightExpr->buildIR(cfg);

    string var = cfg->createNewTmpVar(INT64_T);

    switch (operation) {
        case EQUAL:
            cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::EQUAL_EQUAL, var, var1, var2));
            break;
        case NOT_EQUAL:
            cfg->addIRInstr(new OpInstr(cfg->currentBB, OpInstr::NOT_EQUAL, var, var1, var2));
            break;
    }
    return var;
}



#include "ExprOrOperation.h"

ExprOrOperation::ExprOrOperation(Expr *left, Expr *right) : ExprOperation(left, right) {

}

long ExprOrOperation::simplify() {
    return leftExpr->simplify() || rightExpr->simplify();
}

string ExprOrOperation::buildIR(CFG *cfg) {

    // TODO If statement
    return std::__cxx11::string();
}

#include "ExprCommaOperation.h"

using std::string;

ExprCommaOperation::ExprCommaOperation(Expr *left, Expr *right, Type type) : ExprOperation(left, right, type) {}

string ExprCommaOperation::buildIR(CFG *cfg) {
    string var1 = leftExpr->buildIR(cfg);
    string var2 = rightExpr->buildIR(cfg);

    return var2;
}

bool ExprCommaOperation::isSimplifiable() {
    return leftExpr->isSimplifiable() && rightExpr->isSimplifiable();
}

long ExprCommaOperation::simplify() {
    return rightExpr->simplify();
}

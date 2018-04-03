#include "ExprParenthesis.h"

using std::string;

ExprParenthesis::ExprParenthesis(Expr *expr) : expr(expr) {}

bool ExprParenthesis::isSimplifiable() {
    return expr->isSimplifiable();
}

long ExprParenthesis::simplify() {
    return expr->simplify();
}

string ExprParenthesis::buildIR(CFG *cfg) {
    return expr->buildIR(cfg);
}

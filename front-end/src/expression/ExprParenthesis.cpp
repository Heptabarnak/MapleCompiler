#include "ExprParenthesis.h"

ExprParenthesis::ExprParenthesis(Expr *expr) : expr(expr) {}

bool ExprParenthesis::isSimplifiable() {
    return expr->isSimplifiable();
}

long ExprParenthesis::simplify() {
    return expr->simplify();
}

std::string ExprParenthesis::buildIR(CFG *cfg) {

    return expr->buildIR(cfg);


}

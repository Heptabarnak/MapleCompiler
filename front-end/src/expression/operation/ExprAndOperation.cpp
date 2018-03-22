#include "ExprAndOperation.h"

ExprAndOperation::ExprAndOperation(Expr *left, Expr *right) : ExprOperation(left, right) {

}

long ExprAndOperation::simplify() {
    return leftExpr->simplify() && rightExpr->simplify();
}

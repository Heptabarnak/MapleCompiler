#include "ExprBinaryAndOperation.h"

ExprBinaryAndOperation::ExprBinaryAndOperation(Expr *left, Expr *right) : ExprBinaryOperation(left, right) {

}

long ExprBinaryAndOperation::simplify() {
    return leftExpr->simplify() & rightExpr->simplify();
}

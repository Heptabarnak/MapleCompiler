#include "ExprBinaryXorOperation.h"

ExprBinaryXorOperation::ExprBinaryXorOperation(Expr *left, Expr *right) : ExprBinaryOperation(left, right) {

}

long ExprBinaryXorOperation::simplify() {
    return leftExpr->simplify() ^ rightExpr->simplify();
}

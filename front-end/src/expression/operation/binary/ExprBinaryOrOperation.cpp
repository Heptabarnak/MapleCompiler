#include "ExprBinaryOrOperation.h"


ExprBinaryOrOperation::ExprBinaryOrOperation(Expr *left, Expr *right) : ExprBinaryOperation(left, right) {

}

long ExprBinaryOrOperation::simplify() {
    return leftExpr->simplify() | rightExpr->simplify();
}

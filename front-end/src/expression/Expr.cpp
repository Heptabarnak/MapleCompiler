#include "Expr.h"

bool Expr::optimisationEnable = false;

Expr::Expr(Type type):type(type){
}

Type Expr::getType() const {
    return type;
}

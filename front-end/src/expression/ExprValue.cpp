#include "ExprValue.h"


ExprValue::ExprValue(Value *v)
        : value(v) {
}

bool ExprValue::isSimplifiable() {
    return true;
}

long ExprValue::simplify() {
    return value->getValue();
}

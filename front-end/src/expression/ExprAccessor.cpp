#include "ExprAccessor.h"

using std::string;

ExprAccessor::ExprAccessor(Accessor *accessor, Type type) : accessor(accessor), Expr(type) {}

string ExprAccessor::buildIR(CFG *cfg) {
    return accessor->buildIR(cfg);
}

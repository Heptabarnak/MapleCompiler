#include "ExprAccessor.h"

ExprAccessor::ExprAccessor(Accessor *accessor) : accessor(accessor) {}

string ExprAccessor::buildIR(CFG *cfg) {
    return accessor->getSymbolName();
}

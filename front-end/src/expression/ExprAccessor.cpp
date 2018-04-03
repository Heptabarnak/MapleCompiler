#include "ExprAccessor.h"

using std::string;

ExprAccessor::ExprAccessor(Accessor *accessor) : accessor(accessor) {}

string ExprAccessor::buildIR(CFG *cfg) {
    return accessor->buildIR(cfg);
}

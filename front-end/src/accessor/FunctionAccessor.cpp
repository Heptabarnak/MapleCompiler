

#include "FunctionAccessor.h"

FunctionAccessor::FunctionAccessor(AccessorFunction *accessorFunction) : accessorFunction(accessorFunction) {}

string FunctionAccessor::getSymbolName() {
    return accessorFunction->getSymbolName();
}

string FunctionAccessor::buildIR(CFG *cfg) {
    return accessorFunction->buildIR(cfg);
}

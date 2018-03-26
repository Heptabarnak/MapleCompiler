

#include "FunctionAccessor.h"

FunctionAccessor::FunctionAccessor(AccessorFunction *accessorFunction) : accessorFunction(accessorFunction) {}

string FunctionAccessor::getSymbolName() {
    return accessorFunction->getSymbolName();
}

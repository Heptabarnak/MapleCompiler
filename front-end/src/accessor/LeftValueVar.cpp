

#include "LeftValueVar.h"

LeftValueVar::LeftValueVar(VarAccessor *varAccessor) : varAccessor(varAccessor) {}

std::string LeftValueVar::getSymbolName() {
    return varAccessor->getName();
}


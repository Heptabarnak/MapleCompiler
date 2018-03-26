#include "VarAccessor.h"

VarAccessor::VarAccessor(VarDeclaration *dec) : declaration(dec) {}

std::string VarAccessor::getName() {
    return declaration->getName();
}


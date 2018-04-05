#include "VarAccessor.h"

using std::string;

VarAccessor::VarAccessor(VarDeclaration *dec) : declaration(dec) {}

string VarAccessor::buildIR(CFG *cfg) {
    return declaration->getName();
}

string VarAccessor::getSymbolName() {
    return declaration->getName();
}

Type VarAccessor::getType() {
    return declaration->getType();
}

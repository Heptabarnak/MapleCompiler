#include "FunctionDefinition.h"

FunctionDefinition::FunctionDefinition(Type type, const string &name) : type(type), name(name) {}

string FunctionDefinition::getSymbolName() {
    return name;
}

void FunctionDefinition::setBlockFunction(BlockFunction *block) {
    this->block = block;
}

void FunctionDefinition::setArguments(const vector<FunctionParam *> &params) {
    this->params = params;
}

#include "FunctionDefinition.h"

FunctionDefinition::FunctionDefinition(BlockFunction *block, Type type, const vector<FunctionParam *> &params,
                                       const string &name) : block(block), type(type), params(params), name(name) {}

string FunctionDefinition::getSymbolName() {
    return name;
}

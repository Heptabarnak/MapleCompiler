#include "FunctionDefinition.h"

FunctionDefinition::FunctionDefinition(BlockFunction *block, Type type, const list<FunctionParam *> &params,
                                       const string &name) : block(block), type(type), params(params), name(name) {}

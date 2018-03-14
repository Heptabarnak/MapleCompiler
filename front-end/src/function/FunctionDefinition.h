#ifndef MAPLECOMPILER_FUNCTIONDEFINITION_H
#define MAPLECOMPILER_FUNCTIONDEFINITION_H


#include <string>
#include <list>
#include <token/Type.h>
#include "BlockFunction.h"
#include "FunctionParam.h"

using std::string;
using std::list;

class FunctionDefinition {

private:
    BlockFunction *block;
    Type type;
    list<FunctionParam *> params;
    string name;

public:
    FunctionDefinition(BlockFunction *block, Type type, const list<FunctionParam *> &params, const string &name);
};


#endif //MAPLECOMPILER_FUNCTIONDEFINITION_H

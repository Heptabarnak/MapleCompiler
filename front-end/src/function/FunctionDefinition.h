#ifndef MAPLECOMPILER_FUNCTIONDEFINITION_H
#define MAPLECOMPILER_FUNCTIONDEFINITION_H


#include <string>
#include <vector>
#include <token/Type.h>
#include <declaration/Declaration.h>
#include "BlockFunction.h"
#include "FunctionParam.h"

using std::string;
using std::vector;

class FunctionDefinition : public Declaration {

private:
    BlockFunction *block;
    Type type;
    vector<FunctionParam *> params;
    string name;

public:
    FunctionDefinition(BlockFunction *block, Type type, const vector<FunctionParam *> &params, const string &name);
};


#endif //MAPLECOMPILER_FUNCTIONDEFINITION_H

#ifndef MAPLECOMPILER_ACCESSORFUNCTION_H
#define MAPLECOMPILER_ACCESSORFUNCTION_H

#include <vector>
#include <expression/Expr.h>
#include "FunctionDefinition.h"

using std::vector;

class AccessorFunction {

private:
    FunctionDefinition *declaration;
    vector<Expr *> arguments;

public:
    AccessorFunction(FunctionDefinition *declaration, const vector<Expr *> &arguments);
};


#endif //MAPLECOMPILER_ACCESSORFUNCTION_H

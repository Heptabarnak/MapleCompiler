#ifndef MAPLECOMPILER_ACCESSORFUNCTION_H
#define MAPLECOMPILER_ACCESSORFUNCTION_H

#include <list>
#include <expression/Expr.h>
#include "FunctionDefinition.h"

using std::list;

class AccessorFunction {

private:
    FunctionDefinition *declaration;
    list<Expr *> arguments;

public:
    AccessorFunction(FunctionDefinition *declaration, const list<Expr *> &arguments);
};


#endif //MAPLECOMPILER_ACCESSORFUNCTION_H

#ifndef MAPLECOMPILER_FUNCTIONACCESSOR_H
#define MAPLECOMPILER_FUNCTIONACCESSOR_H


#include <function/AccessorFunction.h>
#include "Accessor.h"

class FunctionAccessor : public Accessor {

private:
    AccessorFunction* accessorFunction;

public:
    FunctionAccessor(AccessorFunction *accessorFunction);

};


#endif //MAPLECOMPILER_FUNCTIONACCESSOR_H

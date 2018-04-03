#ifndef MAPLECOMPILER_FUNCTIONACCESSOR_H
#define MAPLECOMPILER_FUNCTIONACCESSOR_H


#include <function/AccessorFunction.h>
#include "Accessor.h"

class FunctionAccessor : public Accessor {

private:
    AccessorFunction* accessorFunction;

public:
    explicit FunctionAccessor(AccessorFunction *accessorFunction);

    std::string getSymbolName() override;

    std::string buildIR(CFG *cfg);
};


#endif //MAPLECOMPILER_FUNCTIONACCESSOR_H

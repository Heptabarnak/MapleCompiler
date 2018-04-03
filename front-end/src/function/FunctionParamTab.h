#ifndef MAPLECOMPILER_FUNCTIONPARAMTAB_H
#define MAPLECOMPILER_FUNCTIONPARAMTAB_H

#include "FunctionParam.h"

class FunctionParamTab : public FunctionParam {

public:
    long size;

    explicit FunctionParamTab(const std::string &name, Type type, long size = -1);
};


#endif //MAPLECOMPILER_FUNCTIONPARAMTAB_H

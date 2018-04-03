#ifndef MAPLECOMPILER_FUNCTIONPARAMTAB_H
#define MAPLECOMPILER_FUNCTIONPARAMTAB_H

#include "FunctionParam.h"

class FunctionParamTab : public FunctionParam {

public:
    int size;

    explicit FunctionParamTab(const std::string &name = "param", Type type = INT64_T, int size = -1);
};


#endif //MAPLECOMPILER_FUNCTIONPARAMTAB_H

#ifndef MAPLECOMPILER_FUNCTIONPARAMTAB_H
#define MAPLECOMPILER_FUNCTIONPARAMTAB_H

#include <array/TabDeclaration.h>
#include "FunctionParam.h"

class FunctionParamTab : public FunctionParam, public TabDeclaration {
public:
    FunctionParamTab(Type type, long size, const std::string &name);

    FunctionParamTab(Type type);

    Type getType() override;

    std::string getName() override;

};


#endif //MAPLECOMPILER_FUNCTIONPARAMTAB_H

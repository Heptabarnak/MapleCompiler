#ifndef MAPLECOMPILER_FUNCTIONPARAMVAR_H
#define MAPLECOMPILER_FUNCTIONPARAMVAR_H

#include "FunctionParam.h"

class FunctionParamVar : public FunctionParam, public VarDeclaration {
public:
    FunctionParamVar(const std::string &name, Type type);

    explicit FunctionParamVar(Type type);

    Type getType() override;

    std::string getName() override;
};


#endif //MAPLECOMPILER_FUNCTIONPARAMVAR_H

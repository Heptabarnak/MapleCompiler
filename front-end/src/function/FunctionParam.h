#ifndef MAPLECOMPILER_FUNCTIONPARAM_H
#define MAPLECOMPILER_FUNCTIONPARAM_H

#include <string>
#include <token/Type.h>
#include <variable/VarDeclaration.h>

class FunctionParam : public VarDeclaration {
public:
    FunctionParam(const std::string &name, Type type);

    FunctionParam(Type type);
};


#endif //MAPLECOMPILER_FUNCTIONPARAM_H

#ifndef MAPLECOMPILER_FUNCTIONPARAM_H
#define MAPLECOMPILER_FUNCTIONPARAM_H

#include <string>
#include <token/Type.h>
#include <variable/VarDeclaration.h>

class FunctionParam {
public:

    virtual Type getType() = 0;

    virtual std::string getName() = 0;

    virtual ~FunctionParam() = default;
};


#endif //MAPLECOMPILER_FUNCTIONPARAM_H

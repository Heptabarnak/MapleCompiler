#ifndef MAPLECOMPILER_FUNCTIONPARAM_H
#define MAPLECOMPILER_FUNCTIONPARAM_H

#include <string>
#include <token/Type.h>
#include <variable/VarDeclaration.h>

using std::string;

class FunctionParam : public VarDeclaration {
public:
    FunctionParam(const string &name, Type type);

};


#endif //MAPLECOMPILER_FUNCTIONPARAM_H

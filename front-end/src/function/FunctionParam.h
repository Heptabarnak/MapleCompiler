#ifndef MAPLECOMPILER_FUNCTIONPARAM_H
#define MAPLECOMPILER_FUNCTIONPARAM_H

#include <string>
#include <token/Type.h>

using std::string;

class FunctionParam {
private:
    string name;
    Type type;

public:
    FunctionParam(const string &name, Type type);

};


#endif //MAPLECOMPILER_FUNCTIONPARAM_H

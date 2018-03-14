#ifndef MAPLECOMPILER_LEFTVALUEVAR_H
#define MAPLECOMPILER_LEFTVALUEVAR_H


#include <variable/VarAccessor.h>
#include "LeftValue.h"

class LeftValueVar : public LeftValue {

private:
    VarAccessor *varAccessor;

public:
    LeftValueVar(VarAccessor *varAccessor);
};


#endif //MAPLECOMPILER_LEFTVALUEVAR_H

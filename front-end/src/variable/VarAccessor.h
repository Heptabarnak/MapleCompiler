#ifndef MAPLECOMPILER_VARACCESSOR_H
#define MAPLECOMPILER_VARACCESSOR_H


#include "VarDeclaration.h"

class VarAccessor {

private:
    VarDeclaration *Declaration;
public:
    VarAccessor(VarDeclaration *Declaration);
};


#endif //MAPLECOMPILER_VARACCESSOR_H

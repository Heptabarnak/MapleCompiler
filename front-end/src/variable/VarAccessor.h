#ifndef MAPLECOMPILER_VARACCESSOR_H
#define MAPLECOMPILER_VARACCESSOR_H


#include "VarDeclaration.h"

class VarAccessor {

private:
    VarDeclaration *declaration;

public:
    VarAccessor(VarDeclaration *dec);
    std::string getName ();
};


#endif //MAPLECOMPILER_VARACCESSOR_H

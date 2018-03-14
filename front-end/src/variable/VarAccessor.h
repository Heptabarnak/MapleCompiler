#ifndef ANTLR4CPP_FETCHER_VARACCESSOR_H
#define ANTLR4CPP_FETCHER_VARACCESSOR_H


#include "VarDeclaration.h"

class VarAccessor {

private:
    VarDeclaration *Declaration;
public:
    VarAccessor(VarDeclaration *Declaration);
};


#endif //ANTLR4CPP_FETCHER_VARACCESSOR_H

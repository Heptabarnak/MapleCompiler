#include "Declaration.h"


#ifndef ANTLR4CPP_FETCHER_DECLARATIONOFVAR_H
#define ANTLR4CPP_FETCHER_DECLARATIONOFVAR_H

class DeclarationOfVar{
public:
    DeclarationOfVar(Declaration * varD);
private:
    Declaration * VarDeclaration;
};

#endif //ANTLR4CPP_FETCHER_DECLARATIONOFVAR_H

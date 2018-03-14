#include "Declaration.h"

#ifndef ANTLR4CPP_FETCHER_DECLARATIONOFTAB_H
#define ANTLR4CPP_FETCHER_DECLARATIONOFTAB_H

class DeclarationOfTab{
public:
    DeclarationOfTab(Declaration * tabD);
private:
    Declaration * TabDeclaration;
};

#endif //ANTLR4CPP_FETCHER_DECLARATIONOFTAB_H

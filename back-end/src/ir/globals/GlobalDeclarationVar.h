#ifndef MAPLECOMPILER_GLOBALDECLARATIONVAR_H
#define MAPLECOMPILER_GLOBALDECLARATIONVAR_H


#include <ir/GlobalDeclaration.h>

class GlobalDeclarationVar : public GlobalDeclaration {
public:
    long value = 0;

    explicit GlobalDeclarationVar(const std::string &name, long value);

};


#endif //MAPLECOMPILER_GLOBALDECLARATIONVAR_H

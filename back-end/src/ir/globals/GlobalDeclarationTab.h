#ifndef MAPLECOMPILER_GLOBALDECLARATIONTAB_H
#define MAPLECOMPILER_GLOBALDECLARATIONTAB_H

#include <vector>
#include <ir/GlobalDeclaration.h>

class GlobalDeclarationTab : public GlobalDeclaration {
public:
    std::vector<long> *values;

    GlobalDeclarationTab(const std::string &name, std::vector<long> *values);
};


#endif //MAPLECOMPILER_GLOBALDECLARATIONTAB_H

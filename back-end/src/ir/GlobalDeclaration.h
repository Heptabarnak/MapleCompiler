#ifndef MAPLECOMPILER_GLOBALDECLARATION_H
#define MAPLECOMPILER_GLOBALDECLARATION_H


#include <string>

class GlobalDeclaration {
public:
    std::string name;

    explicit GlobalDeclaration(const std::string &name);

    virtual ~GlobalDeclaration() = default;
};


#endif //MAPLECOMPILER_GLOBALDECLARATION_H

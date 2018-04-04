#ifndef MAPLECOMPILER_GLOBALDECLARATION_H
#define MAPLECOMPILER_GLOBALDECLARATION_H


#include <string>
#include <token/Type.h>

class GlobalDeclaration {
public:
    std::string name;

    Type type;

    explicit GlobalDeclaration(const std::string &name, Type type);

    virtual ~GlobalDeclaration() = default;
};


#endif //MAPLECOMPILER_GLOBALDECLARATION_H

#ifndef MAPLECOMPILER_VARDECLARATION_H
#define MAPLECOMPILER_VARDECLARATION_H

#include <string>
#include <expression/Expr.h>
#include <token/Type.h>
#include <declaration/Declaration.h>

class VarDeclaration : public Declaration {

private:
    std::string name;
    Type type;
    Expr *assignment;
public:
    const std::string &getName() const;

    VarDeclaration(const std::string &name, Type type, Expr *assignment = nullptr);

    std::string buildIR(CFG *cfg) override;

    int getAllocationSize() override;

};


#endif //MAPLECOMPILER_VARDECLARATION_H

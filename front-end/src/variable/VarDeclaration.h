#ifndef MAPLECOMPILER_VARDECLARATION_H
#define MAPLECOMPILER_VARDECLARATION_H

#include <string>
#include <expression/Expr.h>
#include <token/Type.h>
#include <declaration/Declaration.h>

using std::string;

class VarDeclaration : public Declaration {

private:
    string name;
    Type type;
    Expr *assignment;
public:
    const string &getName() const;

public:
    VarDeclaration(const string &name, Type type, Expr *assignment = nullptr);

    string buildIR(CFG *cfg) override ;

};


#endif //MAPLECOMPILER_VARDECLARATION_H

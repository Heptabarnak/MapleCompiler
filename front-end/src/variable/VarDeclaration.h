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
    VarDeclaration(const string &name, Type type, Expr *assignment);

};


#endif //MAPLECOMPILER_VARDECLARATION_H

#ifndef MAPLECOMPILER_TABACCESSOR_H
#define MAPLECOMPILER_TABACCESSOR_H

#include <expression/Expr.h>
#include "TabDeclaration.h"

class TabAccessor {

private:
    TabDeclaration *declaration;
    Expr *pos;

public:
    TabAccessor(TabDeclaration *declaration, Expr *pos);
    std::string getName ();

};


#endif //MAPLECOMPILER_TABACCESSOR_H

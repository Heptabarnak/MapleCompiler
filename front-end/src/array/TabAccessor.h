#ifndef ANTLR4CPP_FETCHER_TABACCESSOR_H
#define ANTLR4CPP_FETCHER_TABACCESSOR_H

#include <expression/Expr.h>
#include "TabDeclaration.h"

class TabAccessor {

private:
    TabDeclaration *declaration;
    Expr *pos;

public:
    TabAccessor(TabDeclaration *declaration, Expr *pos);

};


#endif //ANTLR4CPP_FETCHER_TABACCESSOR_H

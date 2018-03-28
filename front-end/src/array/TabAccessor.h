#ifndef MAPLECOMPILER_TABACCESSOR_H
#define MAPLECOMPILER_TABACCESSOR_H

#include <expression/Expr.h>
#include <ir/BuildIR.h>
#include "TabDeclaration.h"

class TabAccessor : public BuildIR {

private:
    TabDeclaration *declaration;
    Expr *pos;

public:
    TabAccessor(TabDeclaration *declaration, Expr *pos);

    std::string getName();

    string buildIR(CFG *cfg) override;
};


#endif //MAPLECOMPILER_TABACCESSOR_H

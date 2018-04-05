#ifndef MAPLECOMPILER_TABACCESSOR_H
#define MAPLECOMPILER_TABACCESSOR_H

#include <expression/Expr.h>
#include <accessor/LeftValueAccessor.h>
#include "TabDeclaration.h"

class TabAccessor : public LeftValueAccessor {

private:
    TabDeclaration *declaration;
    Expr *pos;

public:
    TabAccessor(TabDeclaration *declaration, Expr *pos = nullptr);

    std::string buildIR(CFG *cfg);

    TabDeclaration *getDeclaration() const;
    std::string getSymbolName() override;
    Expr *getPos() const;

    Type getType() override;
};


#endif //MAPLECOMPILER_TABACCESSOR_H

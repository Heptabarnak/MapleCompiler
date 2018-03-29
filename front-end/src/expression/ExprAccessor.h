#ifndef MAPLECOMPILER_EXPRACCESSOR_H
#define MAPLECOMPILER_EXPRACCESSOR_H


#include <accessor/Accessor.h>
#include "Expr.h"

class ExprAccessor : public Expr {
private:
    Accessor *accessor;

public:
    ExprAccessor(Accessor *accessor);
    std::string buildIR(CFG* cfg);
};


#endif //MAPLECOMPILER_EXPRACCESSOR_H

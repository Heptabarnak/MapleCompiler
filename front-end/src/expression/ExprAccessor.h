#ifndef MAPLECOMPILER_ACCESSOR_H
#define MAPLECOMPILER_ACCESSOR_H


#include <accessor/Accessor.h>
#include "Expr.h"

class ExprAccessor : public Expr {
private:
    Accessor *accessor;

public:
    ExprAccessor(Accessor *accessor);
};


#endif //MAPLECOMPILER_ACCESSOR_H

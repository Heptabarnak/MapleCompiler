#ifndef ANTLR4CPP_FETCHER_ACCESSOR_H
#define ANTLR4CPP_FETCHER_ACCESSOR_H


#include <accessor/Accessor.h>
#include "Expr.h"

class ExprAccessor : public Expr {
private:
    Accessor *accessor;

public:
    ExprAccessor(Accessor *accessor);
};


#endif //ANTLR4CPP_FETCHER_ACCESSOR_H

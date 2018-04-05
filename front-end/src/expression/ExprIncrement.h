#ifndef MAPLECOMPILER_EXPRINCREMENT_H
#define MAPLECOMPILER_EXPRINCREMENT_H

#include <string>
#include <accessor/LeftValueAccessor.h>
#include "Expr.h"

class ExprIncrement : public Expr {

private:
    enum OP {
        PLUS_PLUS,
        MINUS_MINUS
    };


    LeftValueAccessor* leftValue;
    OP op;
    bool isPostfix;

public:
    ExprIncrement(LeftValueAccessor *leftValue, std::string op_str, bool isPostfix, Type type);
    std::string buildIR(CFG* cfg);
};


#endif //MAPLECOMPILER_EXPRINCREMENT_H

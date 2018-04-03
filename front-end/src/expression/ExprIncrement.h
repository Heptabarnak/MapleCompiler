#ifndef MAPLECOMPILER_EXPRINCREMENT_H
#define MAPLECOMPILER_EXPRINCREMENT_H


#include <accessor/LeftValue.h>
#include <string>
#include "Expr.h"

class ExprIncrement : public Expr {

private:
    enum OP {
        PLUS_PLUS,
        MINUS_MINUS
    };


    LeftValue* leftValue;
    OP op;
    bool isPostfix;

public:
    ExprIncrement(LeftValue *leftValue, std::string op_str, bool isPostfix);
    std::string buildIR(CFG* cfg);
};


#endif //MAPLECOMPILER_EXPRINCREMENT_H

#ifndef ANTLR4CPP_FETCHER_EXPROROPERATION_H
#define ANTLR4CPP_FETCHER_EXPROROPERATION_H


#include "ExprOperation.h"

class ExprOrOperation : public ExprOperation {

public:
    ExprOrOperation(Expr * left, Expr * right);

};


#endif //ANTLR4CPP_FETCHER_EXPROROPERATION_H

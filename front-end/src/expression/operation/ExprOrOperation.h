#ifndef MAPLECOMPILER_EXPROROPERATION_H
#define MAPLECOMPILER_EXPROROPERATION_H


#include "ExprOperation.h"

class ExprOrOperation : public ExprOperation {

public:
    ExprOrOperation(Expr * left, Expr * right);

    long simplify() override;

    std::string buildIR(CFG *cfg);

};


#endif //MAPLECOMPILER_EXPROROPERATION_H

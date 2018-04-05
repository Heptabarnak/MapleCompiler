#ifndef MAPLECOMPILER_EXPRBINARYOROPERATION_H
#define MAPLECOMPILER_EXPRBINARYOROPERATION_H

#include "ExprBinaryOperation.h"

class ExprBinaryOrOperation : public ExprBinaryOperation {

public:
    ExprBinaryOrOperation(Expr *left, Expr *right, Type type);

    long simplify() override;

    std::string buildIR(CFG *cfg);
};

#endif //MAPLECOMPILER_EXPRBINARYOROPERATION_H

#ifndef MAPLECOMPILER_EXPRBINARYXOROPERATION_H
#define MAPLECOMPILER_EXPRBINARYXOROPERATION_H

#include "ExprBinaryOperation.h"

class ExprBinaryXorOperation : public ExprBinaryOperation {

public:
    ExprBinaryXorOperation(Expr *left, Expr *right);

    long simplify() override;

    std::string buildIR(CFG *cfg);
};

#endif //MAPLECOMPILER_EXPRBINARYXOROPERATION_H

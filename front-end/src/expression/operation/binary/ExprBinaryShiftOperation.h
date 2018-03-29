#ifndef MAPLECOMPILER_EXPRBINARYSHIFTOPERATION_H
#define MAPLECOMPILER_EXPRBINARYSHIFTOPERATION_H

#include <string>
#include "ExprBinaryOperation.h"


class ExprBinaryShiftOperation : public ExprBinaryOperation {
private:
    enum BinaryShiftOperation {
        RIGHT,
        LEFT
    };

    BinaryShiftOperation operation;
public:
    ExprBinaryShiftOperation(Expr *left, Expr *right, const std::string &op);

    long simplify() override;

    std::string buildIR(CFG *cfg) override;
};


#endif //MAPLECOMPILER_EXPRBINARYSHIFTOPERATION_H

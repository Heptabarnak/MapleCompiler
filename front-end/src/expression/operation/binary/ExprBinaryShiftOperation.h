#ifndef MAPLECOMPILER_EXPRBINARYSHIFTOPERATION_H
#define MAPLECOMPILER_EXPRBINARYSHIFTOPERATION_H

#include <string>
#include "ExprBinaryOperation.h"

using std::string;

class ExprBinaryShiftOperation : public ExprBinaryOperation {
private:
    enum BinaryShiftOperation {
        RIGHT,
        LEFT
    };

    BinaryShiftOperation operation;
public:
    ExprBinaryShiftOperation(Expr *left, Expr *right, const string &op);

    long simplify() override;
};


#endif //MAPLECOMPILER_EXPRBINARYSHIFTOPERATION_H

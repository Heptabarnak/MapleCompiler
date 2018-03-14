#ifndef ANTLR4CPP_FETCHER_EXPRBINARYSHIFTOPERATION_H
#define ANTLR4CPP_FETCHER_EXPRBINARYSHIFTOPERATION_H

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
};


#endif //ANTLR4CPP_FETCHER_EXPRBINARYSHIFTOPERATION_H

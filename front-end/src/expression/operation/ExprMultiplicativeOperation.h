#ifndef MAPLECOMPILER_EXPRMULTIPLICATIVEOPERATION_H
#define MAPLECOMPILER_EXPRMULTIPLICATIVEOPERATION_H

#include <string>
#include "ExprOperation.h"


class ExprMultiplicativeOperation : public ExprOperation {
private:
    enum MultiplicativeOperation {
        MULT,
        DIV,
        MOD
    };

    MultiplicativeOperation operation;

public:
    ExprMultiplicativeOperation(Expr *left, Expr *right, const std::string &op, Type type);

    std::string buildIR(CFG *cfg);

    long simplify() override;
};


#endif //MAPLECOMPILER_EXPRMULTIPLICATIVEOPERATION_H

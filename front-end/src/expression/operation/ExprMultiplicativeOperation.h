#ifndef MAPLECOMPILER_EXPRMULTIPLICATIVEOPERATION_H
#define MAPLECOMPILER_EXPRMULTIPLICATIVEOPERATION_H

#include <string>
#include "ExprOperation.h"

using std::string;

class ExprMultiplicativeOperation : public ExprOperation {
private:
    enum MultiplicativeOperation {
        MULT,
        DIV,
        MOD
    };

    MultiplicativeOperation operation;

public:
    ExprMultiplicativeOperation(Expr *left, Expr *right, const string &op);

    string buildIR(CFG *cfg) override;

    long simplify() override;
};


#endif //MAPLECOMPILER_EXPRMULTIPLICATIVEOPERATION_H

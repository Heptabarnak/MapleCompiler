#ifndef MAPLECOMPILER_RETURNSTATEMENT_H
#define MAPLECOMPILER_RETURNSTATEMENT_H


#include <expression/Expr.h>
#include "Instruction.h"

class ReturnStatement : public Instruction {

private:
    Expr *expr;

public:
    explicit ReturnStatement(Expr *expr);
    ~ReturnStatement();

    std::string buildIR(CFG *cfg);
};


#endif //MAPLECOMPILER_RETURNSTATEMENT_H

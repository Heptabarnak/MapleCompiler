#ifndef MAPLECOMPILER_STATEMENT_H
#define MAPLECOMPILER_STATEMENT_H

#include <expression/Expr.h>
#include "Instruction.h"

class Statement : public Instruction {
public:
    explicit Statement(Expr *e);
    ~Statement();

    std::string buildIR(CFG *cfg) override;

private:
    Expr *expr;
};

#endif //MAPLECOMPILER_STATEMENT_H

#ifndef MAPLECOMPILER_EXPRVALUE_H
#define MAPLECOMPILER_EXPRVALUE_H


#include <string>
#include "Expr.h"
#include "Value.h"

class ExprValue : public Expr {
private:
    Value *value;

public:
    explicit ExprValue(Value *v);

    bool isSimplifiable() override;

    long simplify() override;

    std::string buildIR(CFG* cfg);

};

#endif //MAPLECOMPILER_EXPRVALUE_H

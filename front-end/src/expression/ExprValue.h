#ifndef MAPLECOMPILER_EXPRVALUE_H
#define MAPLECOMPILER_EXPRVALUE_H


#include <string>
#include "Expr.h"
#include "Value.h"

using std::string;

class ExprValue : public Expr {
private:
    Value *value;

public:
    explicit ExprValue(Value *v);

    bool isSimplifiable() override;

    long simplify() override;

};

#endif //MAPLECOMPILER_EXPRVALUE_H

#ifndef ANTLR4CPP_FETCHER_EXPRVALUE_H
#define ANTLR4CPP_FETCHER_EXPRVALUE_H


#include <string>
#include "Expr.h"
#include "Value.h"

using std::string;

class ExprValue : public Expr {
private:
    Value *value;

public:
    explicit ExprValue(Value *v);

};

#endif //ANTLR4CPP_FETCHER_EXPRVALUE_H

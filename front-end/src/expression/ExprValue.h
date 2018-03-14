#ifndef ANTLR4CPP_FETCHER_EXPRVALUE_H
#define ANTLR4CPP_FETCHER_EXPRVALUE_H


#include <string>
#include "Expr.h"

using std::string;

class ExprValue : public Expr {
private:
    string integer;
    string character;

public:

    ExprValue(string i, string c);

};

#endif //ANTLR4CPP_FETCHER_EXPRVALUE_H

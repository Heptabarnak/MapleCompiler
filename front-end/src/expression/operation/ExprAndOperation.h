#ifndef ANTLR4CPP_FETCHER_EXPRANDOPERATION_H
#define ANTLR4CPP_FETCHER_EXPRANDOPERATION_H


#include "ExprOperation.h"

class ExprAndOperation : public ExprOperation {

public:
    ExprAndOperation(Expr * left, Expr * right);
};


#endif //ANTLR4CPP_FETCHER_EXPRANDOPERATION_H

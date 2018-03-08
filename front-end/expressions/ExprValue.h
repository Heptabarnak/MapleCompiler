#ifndef ANTLR4CPP_FETCHER_EXPRVALUE_H
#define ANTLR4CPP_FETCHER_EXPRVALUE_H


#include <string>


class ExprValue {
private:
    std::string integer;
    std::string character;

public:

    ExprValue(std::string i, std::string c);

    int64_t eval();

};

#endif //ANTLR4CPP_FETCHER_EXPRVALUE_H

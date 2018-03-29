#ifndef MAPLECOMPILER_EXPRPREFIXUNARY_H
#define MAPLECOMPILER_EXPRPREFIXUNARY_H

#include <string>
#include "ExprUnary.h"

class ExprPrefixUnary : public ExprUnary {
private:
    enum PrefixOperation {
        PLUS,
        MINUS,
        NOT,
        BITWISE_NOT
    };

    PrefixOperation prefixOp;

public:
    ExprPrefixUnary(Expr *expr, const std::string &op);

    bool isSimplifiable() override;

    long simplify() override;

    std::string buildIR(CFG* cfg);

};


#endif //MAPLECOMPILER_EXPRPREFIXUNARY_H

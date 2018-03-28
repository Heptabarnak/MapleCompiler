#ifndef MAPLECOMPILER_EXPRPREFIXUNARY_H
#define MAPLECOMPILER_EXPRPREFIXUNARY_H

#include <string>
#include "ExprUnary.h"

using std::string;

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
    ExprPrefixUnary(Expr *expr, const string &op);

    bool isSimplifiable() override;

    long simplify() override;

    string buildIR(CFG* cfg);

};


#endif //MAPLECOMPILER_EXPRPREFIXUNARY_H

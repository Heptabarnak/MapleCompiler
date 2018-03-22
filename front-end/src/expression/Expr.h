#ifndef MAPLECOMPILER_EXPR_H
#define MAPLECOMPILER_EXPR_H

#include <stdexcept>


class Expr {
public:
    Expr() = default;


    virtual bool isSimplifiable() {
        return false;
    }

    virtual long simplify() {
        throw std::runtime_error("Tried to simplify a not simplifiable expression");
    }
};

#endif //MAPLECOMPILER_EXPR_H

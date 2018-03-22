#ifndef MAPLECOMPILER_EXPR_H
#define MAPLECOMPILER_EXPR_H

#include <stdexcept>


class Expr {
public:
    Expr() = default;


    virtual bool virtual isSimplifiable() {
        return false;
    }

    virtual long virtual simplify() {
        throw std::runtime_error("Tried to simplify a not simplifiable expression");
    }
};

#endif //MAPLECOMPILER_EXPR_H

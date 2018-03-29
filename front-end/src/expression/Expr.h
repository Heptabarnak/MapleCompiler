#ifndef MAPLECOMPILER_EXPR_H
#define MAPLECOMPILER_EXPR_H

#include <stdexcept>
#include <ir/BuildIR.h>


class Expr : public BuildIR {
protected:
    static bool optimisationEnable;
public:
    Expr() = default;

    static inline void setOptimisation(bool enable) { optimisationEnable = enable; }

    virtual bool isSimplifiable() {
        return false;
    }

    virtual long simplify() {
        throw std::runtime_error("Tried to simplify a not simplifiable expression");
    }
};

#endif //MAPLECOMPILER_EXPR_H

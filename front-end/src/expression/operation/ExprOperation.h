#ifndef MAPLECOMPILER_EXPROPERATION_H
#define MAPLECOMPILER_EXPROPERATION_H

#include <expression/Expr.h>
#include <expression/ExprValue.h>
#include <expression/Value.h>
#include <token/Type.h>

class ExprOperation : public Expr {
protected:
    Expr *leftExpr;
    Expr *rightExpr;

    ExprOperation(Expr *left, Expr *right, Type type) {
        // We try to simplify expression when we construct.

        if (!Expr::optimisationEnable || dynamic_cast<ExprValue *>(left) || !left->isSimplifiable()) {
            leftExpr = left;
        } else {
            leftExpr = new ExprValue(new Value(
                    Type::INT64_T,
                    left->simplify(),

            ), type);

            delete left;
        }

        if (!Expr::optimisationEnable || dynamic_cast<ExprValue *>(right) || !right->isSimplifiable()) {
            rightExpr = right;
        } else {
            rightExpr = new ExprValue(new Value(
                    Type::INT64_T,
                    right->simplify()
            ), type);

            delete right;
        }
    }


public:
    bool isSimplifiable() override {
        return leftExpr->isSimplifiable() && rightExpr->isSimplifiable();
    }

};


#endif //MAPLECOMPILER_EXPROPERATION_H

#include "ReturnStatement.h"

ReturnStatement::ReturnStatement(Expr *expr) : expr(expr) {}

ReturnStatement::~ReturnStatement() {
    delete expr;
}

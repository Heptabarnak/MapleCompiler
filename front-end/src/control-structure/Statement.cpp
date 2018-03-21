#include "Statement.h"

Statement::Statement(Expr *e) : expr(e) {}

Statement::~Statement() {
    delete expr;
}

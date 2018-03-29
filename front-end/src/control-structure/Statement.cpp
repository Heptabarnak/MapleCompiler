#include "Statement.h"

Statement::Statement(Expr *e) : expr(e) {}

Statement::~Statement() {
    delete expr;
}

std::string Statement::buildIR(CFG *cfg) {
    return expr->buildIR(cfg);
}

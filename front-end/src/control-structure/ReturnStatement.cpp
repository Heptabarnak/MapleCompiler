#include "ReturnStatement.h"

using std::string;

ReturnStatement::ReturnStatement(Expr *expr) : expr(expr) {}

ReturnStatement::~ReturnStatement() {
    delete expr;
}

string ReturnStatement::buildIR(CFG *cfg) {
    if (expr != nullptr) {
        expr->buildIR(cfg);
    }

    cfg->currentBB->exitTrue = nullptr;
    cfg->currentBB->exitFalse = nullptr;
    return "";
}

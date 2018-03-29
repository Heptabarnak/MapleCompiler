#include "IfStatement.h"

using std::string;

IfStatement::IfStatement(Expr *c, Instruction *st, Instruction *elseSt) : condition(c), statement(st),
                                                                          elseStatement(elseSt) {}

IfStatement::~IfStatement() {
    delete condition;
    delete statement;
    delete elseStatement;
}

string IfStatement::buildIR(CFG *cfg) {

    auto afterIf = new BasicBlock(cfg, cfg->newBBName());
    auto statementBB = new BasicBlock(cfg, cfg->newBBName());

    // Save existing exits
    afterIf->exitTrue = cfg->currentBB->exitTrue;
    afterIf->exitFalse = cfg->currentBB->exitFalse;

    // Add condition IR to the current BB
    condition->buildIR(cfg);
    cfg->currentBB->exitTrue = statementBB;

    // Add if inner statement to IR
    cfg->addBB(statementBB);
    cfg->currentBB = statementBB;

    statement->buildIR(cfg);

    if (elseStatement == nullptr) {
        cfg->currentBB->exitFalse = afterIf;
    }

    // Add elseBB if present
    if (elseStatement != nullptr) {
        auto elseBB = new BasicBlock(cfg, cfg->newBBName());
        cfg->currentBB->exitFalse = elseBB;

        // Add else inner statement to IR
        cfg->addBB(elseBB);
        cfg->currentBB = elseBB;

        elseStatement->buildIR(cfg);

        cfg->currentBB->exitTrue = afterIf;
    }

    cfg->addBB(afterIf);
    cfg->currentBB = afterIf; // Set current BB after IF
    return nullptr;
}

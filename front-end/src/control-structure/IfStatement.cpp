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

    auto statementBB = new BasicBlock(cfg, cfg->newBBName() + "_INNER_IF");
    auto afterIf = new BasicBlock(cfg, cfg->newBBName() + "_AFTER_IF");
    auto elseBB = afterIf;

    if (elseStatement != nullptr) {
        elseBB = new BasicBlock(cfg, cfg->newBBName() + "_INNER_ELSE");
    }

    // Save existing exits
    afterIf->exitTrue = cfg->currentBB->exitTrue;
    afterIf->exitFalse = cfg->currentBB->exitFalse;

    //================
    // CONDITION TEST
    //================

    condition->buildIR(cfg);

    cfg->currentBB->exitTrue = statementBB;
    cfg->currentBB->exitFalse = elseBB; // Will be afterIf if not else statement


    //================
    // INNER IF BB
    //================

    cfg->addBB(statementBB);
    cfg->currentBB = statementBB;
    cfg->currentBB->exitTrue = afterIf;

    statement->buildIR(cfg);


    //================
    // INNER ELSE BB
    //================

    if (elseStatement != nullptr) {
        cfg->addBB(elseBB);
        cfg->currentBB = elseBB;
        cfg->currentBB->exitTrue = afterIf;

        elseStatement->buildIR(cfg);
    }

    //================
    // AFTER IF BB
    //================

    cfg->addBB(afterIf);
    cfg->currentBB = afterIf; // Set current BB after IF
    return "";
}

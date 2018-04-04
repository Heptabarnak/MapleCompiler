#include "ForStatement.h"

ForStatement::ForStatement(Expr *init, Expr *condition, Expr *post, Instruction *statement) : init(init),
                                                                                              condition(condition),
                                                                                              post(post),
                                                                                              statement(statement) {}

ForStatement::~ForStatement() {

}

std::string ForStatement::buildIR(CFG *cfg) {
    auto conditionBB = new BasicBlock(cfg, cfg->newBBName() + "_COND_FOR");
    auto statementBB = new BasicBlock(cfg, cfg->newBBName() + "_INNER_FOR");
    auto afterForBB = new BasicBlock(cfg, cfg->newBBName() + "_AFTER_FOR");

    // Save existing exits
    afterForBB->exitTrue = cfg->currentBB->exitTrue;
    afterForBB->exitFalse = cfg->currentBB->exitFalse;
    init->buildIR(cfg);

    //=================
    // JUMP TO COND BB
    //=================

    cfg->currentBB->exitFalse = nullptr;
    cfg->currentBB->exitTrue = conditionBB;


    //================
    // CONDITION TEST
    //================

    cfg->addBB(conditionBB);
    cfg->currentBB = conditionBB;

    condition->buildIR(cfg);

    cfg->currentBB->exitTrue = statementBB;
    cfg->currentBB->exitFalse = afterForBB;


    //================
    // INNER WHILE BB
    //================

    cfg->addBB(statementBB);
    cfg->currentBB = statementBB;
    cfg->currentBB->exitTrue = conditionBB;

    statement->buildIR(cfg);
    post->buildIR(cfg);


    //================
    // AFTER WHILE BB
    //================

    cfg->addBB(afterForBB);
    cfg->currentBB = afterForBB;
    return "";
}

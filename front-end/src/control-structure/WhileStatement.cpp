#include "WhileStatement.h"

using std::string;

WhileStatement::WhileStatement(Expr *condition, Instruction *instruction) : condition(condition),
                                                                            instruction(instruction) {}

WhileStatement::~WhileStatement() {
    delete condition;
    delete instruction;
}

string WhileStatement::buildIR(CFG *cfg) {

    auto conditionBB = new BasicBlock(cfg, cfg->newBBName() + "_COND_WHILE");
    auto statementBB = new BasicBlock(cfg, cfg->newBBName() + "_INNER_WHILE");
    auto afterWhile = new BasicBlock(cfg, cfg->newBBName() + "_AFTER_WHILE");

    // Save existing exits
    afterWhile->exitTrue = cfg->currentBB->exitTrue;
    afterWhile->exitFalse = cfg->currentBB->exitFalse;

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
    cfg->currentBB->exitFalse = afterWhile;


    //================
    // INNER WHILE BB
    //================

    cfg->addBB(statementBB);
    cfg->currentBB = statementBB;
    cfg->currentBB->exitTrue = conditionBB;

    instruction->buildIR(cfg);


    //================
    // AFTER WHILE BB
    //================

    cfg->addBB(afterWhile);
    cfg->currentBB = afterWhile;
    return "";
}

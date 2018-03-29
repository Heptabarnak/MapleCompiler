#include "WhileStatement.h"

using std::string;

WhileStatement::WhileStatement(Expr *condition, Instruction *instruction) : condition(condition),
                                                                            instruction(instruction) {}

WhileStatement::~WhileStatement() {
    delete condition;
    delete instruction;
}

string WhileStatement::buildIR(CFG *cfg) {
    auto afterWhile = new BasicBlock(cfg, cfg->newBBName());
    auto conditionBB = new BasicBlock(cfg, cfg->newBBName());
    auto statementBB = new BasicBlock(cfg, cfg->newBBName());

    // Save existing exits
    afterWhile->exitTrue = cfg->currentBB->exitTrue;
    afterWhile->exitFalse = cfg->currentBB->exitFalse;

    // Move to a new BB
    cfg->currentBB->exitTrue = conditionBB;
    cfg->addBB(conditionBB);
    cfg->currentBB = conditionBB;

    // Add condition IR to the conditionBB
    condition->buildIR(cfg);
    cfg->currentBB->exitTrue = statementBB;
    cfg->currentBB->exitFalse = afterWhile;

    // Add while inner statement to IR
    cfg->addBB(statementBB);
    cfg->currentBB = statementBB;

    instruction->buildIR(cfg);

    // Go back to condition test
    cfg->currentBB->exitTrue = conditionBB;

    // While end
    cfg->addBB(afterWhile);
    cfg->currentBB = afterWhile; // Set current BB after While
    return "";
}

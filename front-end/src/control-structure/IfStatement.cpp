#include "IfStatement.h"

IfStatement::IfStatement(Expr *c, Instruction *st, Instruction *elseSt) : condition(c), statement(st),
                                                                          elseStatement(elseSt) {}

IfStatement::~IfStatement() {
    delete condition;
    delete statement;
    delete elseStatement;
}

string IfStatement::buildIR(CFG *cfg) {
    condition->buildIR(cfg);

    auto conditionBB = cfg->currentBB;
    auto statementBB = new BasicBlock(cfg, cfg->newBBName());

    auto afterIf = new BasicBlock(cfg, cfg->newBBName());

    // Affect to after if the current next BB of the function
    afterIf->exitTrue = conditionBB->exitTrue;
    afterIf->exitFalse = conditionBB->exitFalse;

    // Add statement after the condition
    conditionBB->exitTrue = statementBB;
    // TODO Add instruction to the statement


    // If there is an else, the condition will do a jump to it
    // Otherwise, condition will jump directly after the if.
    if (elseStatement != nullptr) {
        auto elseStatementBB = new BasicBlock(cfg, cfg->newBBName());

        // TODO Add instruction to this basic block
        conditionBB->exitFalse = elseStatementBB;
        elseStatementBB->exitTrue = afterIf;
    } else {
        conditionBB->exitFalse = afterIf;
    }

    cfg->addBB(afterIf); // Set current BB after IF
}

#include <ir/instructions/LoadConstInstr.h>
#include "ExprAndOperation.h"

using std::string;

ExprAndOperation::ExprAndOperation(Expr *left, Expr *right, Type type) : ExprOperation(left, right, type) {

}

long ExprAndOperation::simplify() {
    return leftExpr->simplify() && rightExpr->simplify();
}

string ExprAndOperation::buildIR(CFG *cfg) {

    // We want to do something like this:
    //  if (left)
    //  {
    //      if (right) {var = 1;}
    //      else {var=0;}
    //  }
    //  else {var=0;}

    string finalValue = cfg->createNewTmpVar(Type::INT64_T);

    // Two options for the value of an or expression: 0 or 1
    auto falseBB = new BasicBlock(cfg, cfg->newBBName());
    auto trueBB = new BasicBlock(cfg, cfg->newBBName());
    auto nextBB = new BasicBlock(cfg, cfg->newBBName());
    auto rightTestBB = new BasicBlock(cfg, cfg->newBBName());

    // Set return value to 1 or 0
    falseBB->addIRInstr(new LoadConstInstr(falseBB, finalValue, 0));
    trueBB->addIRInstr(new LoadConstInstr(trueBB, finalValue, 1));


    // Save existing exits
    nextBB->exitTrue = cfg->currentBB->exitTrue;
    nextBB->exitFalse = cfg->currentBB->exitFalse;

    // Left test
    leftExpr->buildIR(cfg);

    cfg->currentBB->exitTrue = rightTestBB; // If first test is ok, try with the right expr
    cfg->currentBB->exitFalse = falseBB; // If not, directly jump to 'finalResult = 0'

    cfg->addBB(rightTestBB);
    cfg->currentBB = rightTestBB; // Set rightBB as current BB before 'rightExpr#buildIR()'

    // Right test
    rightExpr->buildIR(cfg);

    cfg->currentBB->exitTrue = trueBB; // If right test is ok, jump to 'finalResult = 1'
    cfg->currentBB->exitFalse = falseBB; // If not, jump to 'finalResult = 0'

    falseBB->exitTrue = nextBB; // Anyway, after all this, jump to a new BasicBlock
    trueBB->exitTrue = nextBB;

    cfg->addBB(falseBB);
    cfg->addBB(trueBB);
    cfg->addBB(nextBB);
    cfg->currentBB = nextBB; // Set the currentBB to a new BB

    return finalValue;
}

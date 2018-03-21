#include "WhileStatement.h"

WhileStatement::WhileStatement(Expr *condition, Instruction *instruction) : condition(condition),
                                                                            instruction(instruction) {}

WhileStatement::~WhileStatement() {
    delete condition;
    delete instruction;
}

#include "IfStatement.h"

IfStatement::IfStatement(Expr *c, Instruction *st, Instruction *elseSt) : condition(c), statement(st),
                                                                          elseStatement(elseSt) {}

IfStatement::~IfStatement() {
    delete condition;
    delete statement;
    delete elseStatement;
}

#include "IfStatement.h"

IfStatement::IfStatement(Expr *c, Instruction *st, ElseStatement *elseSt) : condition(c), statements(st), elseStatement(elseSt) {}

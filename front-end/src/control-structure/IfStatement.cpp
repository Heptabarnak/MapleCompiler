//
// Created by julien on 3/14/18.
//

#include "IfStatement.h"

IfStatement::IfStatement(Expr *c, Instruction *st, ElseStatement *elseSt) : condition(c), statements(st), elseStatement(elseSt) {}

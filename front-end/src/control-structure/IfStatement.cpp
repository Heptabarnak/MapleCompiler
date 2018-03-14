#include "IfStatement.h"

IfStatement::IfStatement(Expr *c, Statement *st, Instruction *elseSt) : condition(c), statement(st),
                                                                        elseStatement(elseSt) {

}

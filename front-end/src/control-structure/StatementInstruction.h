#include "Statement.h"

#ifndef ANTLR4CPP_FETCHER_STATEMENTINSTRUCTION_H
#define ANTLR4CPP_FETCHER_STATEMENTINSTRUCTION_H

class StatementInstruction{
private:
    Statement * statement;
public:
    StatementInstruction(Statement* st);
};

#endif //ANTLR4CPP_FETCHER_STATEMENTINSTRUCTION_H

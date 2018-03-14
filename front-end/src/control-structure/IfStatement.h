#ifndef ANTLR4CPP_FETCHER_IFSTATEMENTINSTRUCTION_H
#define ANTLR4CPP_FETCHER_IFSTATEMENTINSTRUCTION_H

class IfStatement{
private:
    Expr * condition;
    Instruction * statements;
    ElseStatement * elseStatement;
public:
    IfStatement(Expr * c, Instruction * st, ElseStatement * elseSt);
};

#endif //ANTLR4CPP_FETCHER_IFSTATEMENTINSTRUCTION_H

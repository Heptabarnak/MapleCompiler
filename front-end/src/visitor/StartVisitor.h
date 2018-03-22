#ifndef ANTLR4CPP_FETCHER_STARTVISITOR_H
#define ANTLR4CPP_FETCHER_STARTVISITOR_H


#include <axiom/Start.h>
#include <symbol-table/SymbolTable.h>
#include <maple-parser/MapleGrammarVisitor.h>

class StartVisitor : public MapleGrammarVisitor {

private:
    Start *start;
    SymbolTable *currentSymbolTable;

public:
    antlrcpp::Any visitAccessor(MapleGrammarParser::AccessorContext *ctx) override;

    antlrcpp::Any visitAccessorFunction(MapleGrammarParser::AccessorFunctionContext *ctx) override;

    antlrcpp::Any visitAccessorTab(MapleGrammarParser::AccessorTabContext *ctx) override;

    antlrcpp::Any visitAccessorVar(MapleGrammarParser::AccessorVarContext *ctx) override;

    antlrcpp::Any visitArgumentList(MapleGrammarParser::ArgumentListContext *ctx) override;

    antlrcpp::Any visitAssignment(MapleGrammarParser::AssignmentContext *ctx) override;

    antlrcpp::Any visitBlock(MapleGrammarParser::BlockContext *ctx) override;

    antlrcpp::Any visitBlockFunction(MapleGrammarParser::BlockFunctionContext *ctx) override;

    antlrcpp::Any visitDeclaration(MapleGrammarParser::DeclarationContext *ctx) override;

    antlrcpp::Any visitDeclarationTab(MapleGrammarParser::DeclarationTabContext *ctx) override;

    antlrcpp::Any visitDeclarationVar(MapleGrammarParser::DeclarationVarContext *ctx) override;

    antlrcpp::Any visitDeclarationVarDefinition(MapleGrammarParser::DeclarationVarDefinitionContext *context) override;

    antlrcpp::Any visitDefinitionTab(MapleGrammarParser::DefinitionTabContext *ctx) override;

    antlrcpp::Any visitElseStatement(MapleGrammarParser::ElseStatementContext *ctx) override;

    antlrcpp::Any visitExprAccessor(MapleGrammarParser::ExprAccessorContext *ctx) override;

    antlrcpp::Any visitExprAdditive(MapleGrammarParser::ExprAdditiveContext *ctx) override;

    antlrcpp::Any visitExprAffectation(MapleGrammarParser::ExprAffectationContext *ctx) override;

    antlrcpp::Any visitExprAnd(MapleGrammarParser::ExprAndContext *ctx) override;

    antlrcpp::Any visitExprBinaryAnd(MapleGrammarParser::ExprBinaryAndContext *ctx) override;

    antlrcpp::Any visitExprBinaryOr(MapleGrammarParser::ExprBinaryOrContext *ctx) override;

    antlrcpp::Any visitExprBinaryShift(MapleGrammarParser::ExprBinaryShiftContext *ctx) override;

    antlrcpp::Any visitExprBinaryXor(MapleGrammarParser::ExprBinaryXorContext *ctx) override;

    antlrcpp::Any visitExprCompareEquality(MapleGrammarParser::ExprCompareEqualityContext *ctx) override;

    antlrcpp::Any visitExprCompareRelational(MapleGrammarParser::ExprCompareRelationalContext *ctx) override;

    antlrcpp::Any visitExprMultiplicative(MapleGrammarParser::ExprMultiplicativeContext *ctx) override;

    antlrcpp::Any visitExprOr(MapleGrammarParser::ExprOrContext *ctx) override;

    antlrcpp::Any visitExprParenthesis(MapleGrammarParser::ExprParenthesisContext *ctx) override;

    antlrcpp::Any visitExprUnaryPrefix(MapleGrammarParser::ExprUnaryPrefixContext *ctx) override;

    antlrcpp::Any visitExprValue(MapleGrammarParser::ExprValueContext *ctx) override;

    antlrcpp::Any visitFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext *ctx) override;

    antlrcpp::Any visitIfStatement(MapleGrammarParser::IfStatementContext *ctx) override;

    antlrcpp::Any visitInstruction(MapleGrammarParser::InstructionContext *ctx) override;

    antlrcpp::Any visitLeftValue(MapleGrammarParser::LeftValueContext *ctx) override;

    antlrcpp::Any visitProgram(MapleGrammarParser::ProgramContext *ctx) override;

    antlrcpp::Any visitReturnStatement(MapleGrammarParser::ReturnStatementContext *ctx) override;

    antlrcpp::Any visitStart(MapleGrammarParser::StartContext *ctx) override;

    antlrcpp::Any visitStatement(MapleGrammarParser::StatementContext *ctx) override;

    antlrcpp::Any visitTypeList(MapleGrammarParser::TypeListContext *ctx) override;

    antlrcpp::Any visitValue(MapleGrammarParser::ValueContext *ctx) override;

    antlrcpp::Any visitWhileStatement(MapleGrammarParser::WhileStatementContext *ctx) override;

    antlrcpp::Any visitOpUnaryPrefix(MapleGrammarParser::OpUnaryPrefixContext *context) override;

    antlrcpp::Any visitOpMultiplicative(MapleGrammarParser::OpMultiplicativeContext *context) override;

    antlrcpp::Any visitOpAdditive(MapleGrammarParser::OpAdditiveContext *context) override;

    antlrcpp::Any visitOpBinaryShift(MapleGrammarParser::OpBinaryShiftContext *context) override;

    antlrcpp::Any visitOpCompareRelational(MapleGrammarParser::OpCompareRelationalContext *context) override;

    antlrcpp::Any visitOpCompareEquality(MapleGrammarParser::OpCompareEqualityContext *context) override;

    antlrcpp::Any visitOpBinaryAnd(MapleGrammarParser::OpBinaryAndContext *context) override;

    antlrcpp::Any visitOpBinaryXor(MapleGrammarParser::OpBinaryXorContext *context) override;

    antlrcpp::Any visitOpBinaryOr(MapleGrammarParser::OpBinaryOrContext *context) override;

    antlrcpp::Any visitOpAnd(MapleGrammarParser::OpAndContext *context) override;

    antlrcpp::Any visitOpOr(MapleGrammarParser::OpOrContext *context) override;

    antlrcpp::Any visitOpAffectation(MapleGrammarParser::OpAffectationContext *context) override;

    antlrcpp::Any visitOpIncrement(MapleGrammarParser::OpIncrementContext *context) override;

    antlrcpp::Any visitExprIncrementPostfix(MapleGrammarParser::ExprIncrementPostfixContext *context) override;

    antlrcpp::Any visitExprIncrementPrefix(MapleGrammarParser::ExprIncrementPrefixContext *context) override;

};


#endif //ANTLR4CPP_FETCHER_STARTVISITOR_H

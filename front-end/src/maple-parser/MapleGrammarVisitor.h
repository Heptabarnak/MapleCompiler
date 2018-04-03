
// Generated from /home/julien/Documents/Travail/4IF/PLD COMP/MapleCompiler/front-end/src/maple-parser/MapleGrammar.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "MapleGrammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MapleGrammarParser.
 */
class  MapleGrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MapleGrammarParser.
   */
    virtual antlrcpp::Any visitStart(MapleGrammarParser::StartContext *context) = 0;

    virtual antlrcpp::Any visitProgram(MapleGrammarParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitValue(MapleGrammarParser::ValueContext *context) = 0;

    virtual antlrcpp::Any visitOpIncrement(MapleGrammarParser::OpIncrementContext *context) = 0;

    virtual antlrcpp::Any visitOpUnaryPrefix(MapleGrammarParser::OpUnaryPrefixContext *context) = 0;

    virtual antlrcpp::Any visitOpMultiplicative(MapleGrammarParser::OpMultiplicativeContext *context) = 0;

    virtual antlrcpp::Any visitOpAdditive(MapleGrammarParser::OpAdditiveContext *context) = 0;

    virtual antlrcpp::Any visitOpBinaryShift(MapleGrammarParser::OpBinaryShiftContext *context) = 0;

    virtual antlrcpp::Any visitOpCompareRelational(MapleGrammarParser::OpCompareRelationalContext *context) = 0;

    virtual antlrcpp::Any visitOpCompareEquality(MapleGrammarParser::OpCompareEqualityContext *context) = 0;

    virtual antlrcpp::Any visitOpBinaryAnd(MapleGrammarParser::OpBinaryAndContext *context) = 0;

    virtual antlrcpp::Any visitOpBinaryXor(MapleGrammarParser::OpBinaryXorContext *context) = 0;

    virtual antlrcpp::Any visitOpBinaryOr(MapleGrammarParser::OpBinaryOrContext *context) = 0;

    virtual antlrcpp::Any visitOpAnd(MapleGrammarParser::OpAndContext *context) = 0;

    virtual antlrcpp::Any visitOpOr(MapleGrammarParser::OpOrContext *context) = 0;

    virtual antlrcpp::Any visitOpAffectation(MapleGrammarParser::OpAffectationContext *context) = 0;

    virtual antlrcpp::Any visitExprAdditive(MapleGrammarParser::ExprAdditiveContext *context) = 0;

    virtual antlrcpp::Any visitExprValue(MapleGrammarParser::ExprValueContext *context) = 0;

    virtual antlrcpp::Any visitExprBinaryShift(MapleGrammarParser::ExprBinaryShiftContext *context) = 0;

    virtual antlrcpp::Any visitExprAffectation(MapleGrammarParser::ExprAffectationContext *context) = 0;

    virtual antlrcpp::Any visitExprBinaryXor(MapleGrammarParser::ExprBinaryXorContext *context) = 0;

    virtual antlrcpp::Any visitExprBinaryAnd(MapleGrammarParser::ExprBinaryAndContext *context) = 0;

    virtual antlrcpp::Any visitExprIncrementPostfix(MapleGrammarParser::ExprIncrementPostfixContext *context) = 0;

    virtual antlrcpp::Any visitExprOr(MapleGrammarParser::ExprOrContext *context) = 0;

    virtual antlrcpp::Any visitExprMultiplicative(MapleGrammarParser::ExprMultiplicativeContext *context) = 0;

    virtual antlrcpp::Any visitExprAccessor(MapleGrammarParser::ExprAccessorContext *context) = 0;

    virtual antlrcpp::Any visitExprAnd(MapleGrammarParser::ExprAndContext *context) = 0;

    virtual antlrcpp::Any visitExprParenthesis(MapleGrammarParser::ExprParenthesisContext *context) = 0;

    virtual antlrcpp::Any visitExprBinaryOr(MapleGrammarParser::ExprBinaryOrContext *context) = 0;

    virtual antlrcpp::Any visitExprCompareRelational(MapleGrammarParser::ExprCompareRelationalContext *context) = 0;

    virtual antlrcpp::Any visitExprCompareEquality(MapleGrammarParser::ExprCompareEqualityContext *context) = 0;

    virtual antlrcpp::Any visitExprIncrementPrefix(MapleGrammarParser::ExprIncrementPrefixContext *context) = 0;

    virtual antlrcpp::Any visitExprUnaryPrefix(MapleGrammarParser::ExprUnaryPrefixContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationVar(MapleGrammarParser::DeclarationVarContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationTab(MapleGrammarParser::DeclarationTabContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(MapleGrammarParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationVarDefinition(MapleGrammarParser::DeclarationVarDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitDefinitionTab(MapleGrammarParser::DefinitionTabContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(MapleGrammarParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitAccessorTab(MapleGrammarParser::AccessorTabContext *context) = 0;

    virtual antlrcpp::Any visitAccessorVar(MapleGrammarParser::AccessorVarContext *context) = 0;

    virtual antlrcpp::Any visitAccessorFunction(MapleGrammarParser::AccessorFunctionContext *context) = 0;

    virtual antlrcpp::Any visitLeftValue(MapleGrammarParser::LeftValueContext *context) = 0;

    virtual antlrcpp::Any visitAccessor(MapleGrammarParser::AccessorContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(MapleGrammarParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitElseStatement(MapleGrammarParser::ElseStatementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(MapleGrammarParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDeclaration(MapleGrammarParser::FunctionDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(MapleGrammarParser::ReturnStatementContext *context) = 0;

    virtual antlrcpp::Any visitBlockFunction(MapleGrammarParser::BlockFunctionContext *context) = 0;

    virtual antlrcpp::Any visitArgumentList(MapleGrammarParser::ArgumentListContext *context) = 0;

    virtual antlrcpp::Any visitTypeList(MapleGrammarParser::TypeListContext *context) = 0;

    virtual antlrcpp::Any visitTypeListWithoutName(MapleGrammarParser::TypeListWithoutNameContext *context) = 0;

    virtual antlrcpp::Any visitBlock(MapleGrammarParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStatement(MapleGrammarParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitInstruction(MapleGrammarParser::InstructionContext *context) = 0;


};


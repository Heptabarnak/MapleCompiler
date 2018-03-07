
// Generated from F:/Downloads/MapleCompiler/front-end\MapleGrammar.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "MapleGrammarParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MapleGrammarParser.
 */
class  MapleGrammarListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(MapleGrammarParser::StartContext *ctx) = 0;
  virtual void exitStart(MapleGrammarParser::StartContext *ctx) = 0;

  virtual void enterProgram(MapleGrammarParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(MapleGrammarParser::ProgramContext *ctx) = 0;

  virtual void enterValue(MapleGrammarParser::ValueContext *ctx) = 0;
  virtual void exitValue(MapleGrammarParser::ValueContext *ctx) = 0;

  virtual void enterOpUnaryPostfix(MapleGrammarParser::OpUnaryPostfixContext *ctx) = 0;
  virtual void exitOpUnaryPostfix(MapleGrammarParser::OpUnaryPostfixContext *ctx) = 0;

  virtual void enterOpUnaryPrefix(MapleGrammarParser::OpUnaryPrefixContext *ctx) = 0;
  virtual void exitOpUnaryPrefix(MapleGrammarParser::OpUnaryPrefixContext *ctx) = 0;

  virtual void enterOpMultiplicative(MapleGrammarParser::OpMultiplicativeContext *ctx) = 0;
  virtual void exitOpMultiplicative(MapleGrammarParser::OpMultiplicativeContext *ctx) = 0;

  virtual void enterOpAdditive(MapleGrammarParser::OpAdditiveContext *ctx) = 0;
  virtual void exitOpAdditive(MapleGrammarParser::OpAdditiveContext *ctx) = 0;

  virtual void enterOpBinaryShift(MapleGrammarParser::OpBinaryShiftContext *ctx) = 0;
  virtual void exitOpBinaryShift(MapleGrammarParser::OpBinaryShiftContext *ctx) = 0;

  virtual void enterOpCompareRelational(MapleGrammarParser::OpCompareRelationalContext *ctx) = 0;
  virtual void exitOpCompareRelational(MapleGrammarParser::OpCompareRelationalContext *ctx) = 0;

  virtual void enterOpCompareEquality(MapleGrammarParser::OpCompareEqualityContext *ctx) = 0;
  virtual void exitOpCompareEquality(MapleGrammarParser::OpCompareEqualityContext *ctx) = 0;

  virtual void enterOpBinaryAnd(MapleGrammarParser::OpBinaryAndContext *ctx) = 0;
  virtual void exitOpBinaryAnd(MapleGrammarParser::OpBinaryAndContext *ctx) = 0;

  virtual void enterOpBinaryXor(MapleGrammarParser::OpBinaryXorContext *ctx) = 0;
  virtual void exitOpBinaryXor(MapleGrammarParser::OpBinaryXorContext *ctx) = 0;

  virtual void enterOpBinaryOr(MapleGrammarParser::OpBinaryOrContext *ctx) = 0;
  virtual void exitOpBinaryOr(MapleGrammarParser::OpBinaryOrContext *ctx) = 0;

  virtual void enterOpAnd(MapleGrammarParser::OpAndContext *ctx) = 0;
  virtual void exitOpAnd(MapleGrammarParser::OpAndContext *ctx) = 0;

  virtual void enterOpOr(MapleGrammarParser::OpOrContext *ctx) = 0;
  virtual void exitOpOr(MapleGrammarParser::OpOrContext *ctx) = 0;

  virtual void enterOpAffectation(MapleGrammarParser::OpAffectationContext *ctx) = 0;
  virtual void exitOpAffectation(MapleGrammarParser::OpAffectationContext *ctx) = 0;

  virtual void enterExpr(MapleGrammarParser::ExprContext *ctx) = 0;
  virtual void exitExpr(MapleGrammarParser::ExprContext *ctx) = 0;

  virtual void enterDeclarationVar(MapleGrammarParser::DeclarationVarContext *ctx) = 0;
  virtual void exitDeclarationVar(MapleGrammarParser::DeclarationVarContext *ctx) = 0;

  virtual void enterDeclarationTab(MapleGrammarParser::DeclarationTabContext *ctx) = 0;
  virtual void exitDeclarationTab(MapleGrammarParser::DeclarationTabContext *ctx) = 0;

  virtual void enterDeclaration(MapleGrammarParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(MapleGrammarParser::DeclarationContext *ctx) = 0;

  virtual void enterDefinitionTab(MapleGrammarParser::DefinitionTabContext *ctx) = 0;
  virtual void exitDefinitionTab(MapleGrammarParser::DefinitionTabContext *ctx) = 0;

  virtual void enterAssignment(MapleGrammarParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(MapleGrammarParser::AssignmentContext *ctx) = 0;

  virtual void enterAccessorTab(MapleGrammarParser::AccessorTabContext *ctx) = 0;
  virtual void exitAccessorTab(MapleGrammarParser::AccessorTabContext *ctx) = 0;

  virtual void enterAccessorVar(MapleGrammarParser::AccessorVarContext *ctx) = 0;
  virtual void exitAccessorVar(MapleGrammarParser::AccessorVarContext *ctx) = 0;

  virtual void enterAccessorFunction(MapleGrammarParser::AccessorFunctionContext *ctx) = 0;
  virtual void exitAccessorFunction(MapleGrammarParser::AccessorFunctionContext *ctx) = 0;

  virtual void enterLeftValue(MapleGrammarParser::LeftValueContext *ctx) = 0;
  virtual void exitLeftValue(MapleGrammarParser::LeftValueContext *ctx) = 0;

  virtual void enterAccessor(MapleGrammarParser::AccessorContext *ctx) = 0;
  virtual void exitAccessor(MapleGrammarParser::AccessorContext *ctx) = 0;

  virtual void enterIfStatement(MapleGrammarParser::IfStatementContext *ctx) = 0;
  virtual void exitIfStatement(MapleGrammarParser::IfStatementContext *ctx) = 0;

  virtual void enterElseStatement(MapleGrammarParser::ElseStatementContext *ctx) = 0;
  virtual void exitElseStatement(MapleGrammarParser::ElseStatementContext *ctx) = 0;

  virtual void enterWhileStatement(MapleGrammarParser::WhileStatementContext *ctx) = 0;
  virtual void exitWhileStatement(MapleGrammarParser::WhileStatementContext *ctx) = 0;

  virtual void enterFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext *ctx) = 0;
  virtual void exitFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext *ctx) = 0;

  virtual void enterReturnStatement(MapleGrammarParser::ReturnStatementContext *ctx) = 0;
  virtual void exitReturnStatement(MapleGrammarParser::ReturnStatementContext *ctx) = 0;

  virtual void enterBlockFunction(MapleGrammarParser::BlockFunctionContext *ctx) = 0;
  virtual void exitBlockFunction(MapleGrammarParser::BlockFunctionContext *ctx) = 0;

  virtual void enterArgumentList(MapleGrammarParser::ArgumentListContext *ctx) = 0;
  virtual void exitArgumentList(MapleGrammarParser::ArgumentListContext *ctx) = 0;

  virtual void enterTypeList(MapleGrammarParser::TypeListContext *ctx) = 0;
  virtual void exitTypeList(MapleGrammarParser::TypeListContext *ctx) = 0;

  virtual void enterBlock(MapleGrammarParser::BlockContext *ctx) = 0;
  virtual void exitBlock(MapleGrammarParser::BlockContext *ctx) = 0;

  virtual void enterStatement(MapleGrammarParser::StatementContext *ctx) = 0;
  virtual void exitStatement(MapleGrammarParser::StatementContext *ctx) = 0;

  virtual void enterInstruction(MapleGrammarParser::InstructionContext *ctx) = 0;
  virtual void exitInstruction(MapleGrammarParser::InstructionContext *ctx) = 0;


};



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

  virtual void enterOp1(MapleGrammarParser::Op1Context *ctx) = 0;
  virtual void exitOp1(MapleGrammarParser::Op1Context *ctx) = 0;

  virtual void enterOp2(MapleGrammarParser::Op2Context *ctx) = 0;
  virtual void exitOp2(MapleGrammarParser::Op2Context *ctx) = 0;

  virtual void enterOp3(MapleGrammarParser::Op3Context *ctx) = 0;
  virtual void exitOp3(MapleGrammarParser::Op3Context *ctx) = 0;

  virtual void enterOp4(MapleGrammarParser::Op4Context *ctx) = 0;
  virtual void exitOp4(MapleGrammarParser::Op4Context *ctx) = 0;

  virtual void enterOp5(MapleGrammarParser::Op5Context *ctx) = 0;
  virtual void exitOp5(MapleGrammarParser::Op5Context *ctx) = 0;

  virtual void enterOp6(MapleGrammarParser::Op6Context *ctx) = 0;
  virtual void exitOp6(MapleGrammarParser::Op6Context *ctx) = 0;

  virtual void enterOp7(MapleGrammarParser::Op7Context *ctx) = 0;
  virtual void exitOp7(MapleGrammarParser::Op7Context *ctx) = 0;

  virtual void enterOp8(MapleGrammarParser::Op8Context *ctx) = 0;
  virtual void exitOp8(MapleGrammarParser::Op8Context *ctx) = 0;

  virtual void enterOp9(MapleGrammarParser::Op9Context *ctx) = 0;
  virtual void exitOp9(MapleGrammarParser::Op9Context *ctx) = 0;

  virtual void enterOp10(MapleGrammarParser::Op10Context *ctx) = 0;
  virtual void exitOp10(MapleGrammarParser::Op10Context *ctx) = 0;

  virtual void enterOp11(MapleGrammarParser::Op11Context *ctx) = 0;
  virtual void exitOp11(MapleGrammarParser::Op11Context *ctx) = 0;

  virtual void enterOp12(MapleGrammarParser::Op12Context *ctx) = 0;
  virtual void exitOp12(MapleGrammarParser::Op12Context *ctx) = 0;

  virtual void enterOp13(MapleGrammarParser::Op13Context *ctx) = 0;
  virtual void exitOp13(MapleGrammarParser::Op13Context *ctx) = 0;

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

  virtual void enterIf(MapleGrammarParser::IfContext *ctx) = 0;
  virtual void exitIf(MapleGrammarParser::IfContext *ctx) = 0;

  virtual void enterElse(MapleGrammarParser::ElseContext *ctx) = 0;
  virtual void exitElse(MapleGrammarParser::ElseContext *ctx) = 0;

  virtual void enterWhile(MapleGrammarParser::WhileContext *ctx) = 0;
  virtual void exitWhile(MapleGrammarParser::WhileContext *ctx) = 0;

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


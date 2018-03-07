
// Generated from R:/Documents/_INSA/4/PLD COMP/MapleCompiler/front-end\MapleGrammar.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "MapleGrammarVisitor.h"


/**
 * This class provides an empty implementation of MapleGrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MapleGrammarBaseVisitor : public MapleGrammarVisitor {
public:

  virtual antlrcpp::Any visitStart(MapleGrammarParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram(MapleGrammarParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitValue(MapleGrammarParser::ValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpUnaryPostfix(MapleGrammarParser::OpUnaryPostfixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpUnaryPrefix(MapleGrammarParser::OpUnaryPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpMultiplicative(MapleGrammarParser::OpMultiplicativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpAdditive(MapleGrammarParser::OpAdditiveContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpBinaryShift(MapleGrammarParser::OpBinaryShiftContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpCompareRelational(MapleGrammarParser::OpCompareRelationalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpCompareEquality(MapleGrammarParser::OpCompareEqualityContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpBinaryAnd(MapleGrammarParser::OpBinaryAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpBinaryXor(MapleGrammarParser::OpBinaryXorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpBinaryOr(MapleGrammarParser::OpBinaryOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpAnd(MapleGrammarParser::OpAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpOr(MapleGrammarParser::OpOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOpAffectation(MapleGrammarParser::OpAffectationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(MapleGrammarParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationVar(MapleGrammarParser::DeclarationVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarationTab(MapleGrammarParser::DeclarationTabContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(MapleGrammarParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDefinitionTab(MapleGrammarParser::DefinitionTabContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(MapleGrammarParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessorTab(MapleGrammarParser::AccessorTabContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessorVar(MapleGrammarParser::AccessorVarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessorFunction(MapleGrammarParser::AccessorFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLeftValue(MapleGrammarParser::LeftValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAccessor(MapleGrammarParser::AccessorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(MapleGrammarParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElseStatement(MapleGrammarParser::ElseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStatement(MapleGrammarParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStatement(MapleGrammarParser::ReturnStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlockFunction(MapleGrammarParser::BlockFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgumentList(MapleGrammarParser::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeList(MapleGrammarParser::TypeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(MapleGrammarParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(MapleGrammarParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInstruction(MapleGrammarParser::InstructionContext *ctx) override {
    return visitChildren(ctx);
  }


};


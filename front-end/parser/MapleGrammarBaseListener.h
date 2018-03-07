
// Generated from F:/Downloads/MapleCompiler/front-end\MapleGrammar.g4 by ANTLR 4.7

#pragma once


#include "antlr4-runtime.h"
#include "MapleGrammarListener.h"


/**
 * This class provides an empty implementation of MapleGrammarListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  MapleGrammarBaseListener : public MapleGrammarListener {
public:

  virtual void enterStart(MapleGrammarParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(MapleGrammarParser::StartContext * /*ctx*/) override { }

  virtual void enterProgram(MapleGrammarParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(MapleGrammarParser::ProgramContext * /*ctx*/) override { }

  virtual void enterValue(MapleGrammarParser::ValueContext * /*ctx*/) override { }
  virtual void exitValue(MapleGrammarParser::ValueContext * /*ctx*/) override { }

  virtual void enterOpUnaryPostfix(MapleGrammarParser::OpUnaryPostfixContext * /*ctx*/) override { }
  virtual void exitOpUnaryPostfix(MapleGrammarParser::OpUnaryPostfixContext * /*ctx*/) override { }

  virtual void enterOpUnaryPrefix(MapleGrammarParser::OpUnaryPrefixContext * /*ctx*/) override { }
  virtual void exitOpUnaryPrefix(MapleGrammarParser::OpUnaryPrefixContext * /*ctx*/) override { }

  virtual void enterOpMultiplicative(MapleGrammarParser::OpMultiplicativeContext * /*ctx*/) override { }
  virtual void exitOpMultiplicative(MapleGrammarParser::OpMultiplicativeContext * /*ctx*/) override { }

  virtual void enterOpAdditive(MapleGrammarParser::OpAdditiveContext * /*ctx*/) override { }
  virtual void exitOpAdditive(MapleGrammarParser::OpAdditiveContext * /*ctx*/) override { }

  virtual void enterOpBinaryShift(MapleGrammarParser::OpBinaryShiftContext * /*ctx*/) override { }
  virtual void exitOpBinaryShift(MapleGrammarParser::OpBinaryShiftContext * /*ctx*/) override { }

  virtual void enterOpCompareRelational(MapleGrammarParser::OpCompareRelationalContext * /*ctx*/) override { }
  virtual void exitOpCompareRelational(MapleGrammarParser::OpCompareRelationalContext * /*ctx*/) override { }

  virtual void enterOpCompareEquality(MapleGrammarParser::OpCompareEqualityContext * /*ctx*/) override { }
  virtual void exitOpCompareEquality(MapleGrammarParser::OpCompareEqualityContext * /*ctx*/) override { }

  virtual void enterOpBinaryAnd(MapleGrammarParser::OpBinaryAndContext * /*ctx*/) override { }
  virtual void exitOpBinaryAnd(MapleGrammarParser::OpBinaryAndContext * /*ctx*/) override { }

  virtual void enterOpBinaryXor(MapleGrammarParser::OpBinaryXorContext * /*ctx*/) override { }
  virtual void exitOpBinaryXor(MapleGrammarParser::OpBinaryXorContext * /*ctx*/) override { }

  virtual void enterOpBinaryOr(MapleGrammarParser::OpBinaryOrContext * /*ctx*/) override { }
  virtual void exitOpBinaryOr(MapleGrammarParser::OpBinaryOrContext * /*ctx*/) override { }

  virtual void enterOpAnd(MapleGrammarParser::OpAndContext * /*ctx*/) override { }
  virtual void exitOpAnd(MapleGrammarParser::OpAndContext * /*ctx*/) override { }

  virtual void enterOpOr(MapleGrammarParser::OpOrContext * /*ctx*/) override { }
  virtual void exitOpOr(MapleGrammarParser::OpOrContext * /*ctx*/) override { }

  virtual void enterOpAffectation(MapleGrammarParser::OpAffectationContext * /*ctx*/) override { }
  virtual void exitOpAffectation(MapleGrammarParser::OpAffectationContext * /*ctx*/) override { }

  virtual void enterExpr(MapleGrammarParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(MapleGrammarParser::ExprContext * /*ctx*/) override { }

  virtual void enterDeclarationVar(MapleGrammarParser::DeclarationVarContext * /*ctx*/) override { }
  virtual void exitDeclarationVar(MapleGrammarParser::DeclarationVarContext * /*ctx*/) override { }

  virtual void enterDeclarationTab(MapleGrammarParser::DeclarationTabContext * /*ctx*/) override { }
  virtual void exitDeclarationTab(MapleGrammarParser::DeclarationTabContext * /*ctx*/) override { }

  virtual void enterDeclaration(MapleGrammarParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(MapleGrammarParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterDefinitionTab(MapleGrammarParser::DefinitionTabContext * /*ctx*/) override { }
  virtual void exitDefinitionTab(MapleGrammarParser::DefinitionTabContext * /*ctx*/) override { }

  virtual void enterAssignment(MapleGrammarParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(MapleGrammarParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterAccessorTab(MapleGrammarParser::AccessorTabContext * /*ctx*/) override { }
  virtual void exitAccessorTab(MapleGrammarParser::AccessorTabContext * /*ctx*/) override { }

  virtual void enterAccessorVar(MapleGrammarParser::AccessorVarContext * /*ctx*/) override { }
  virtual void exitAccessorVar(MapleGrammarParser::AccessorVarContext * /*ctx*/) override { }

  virtual void enterAccessorFunction(MapleGrammarParser::AccessorFunctionContext * /*ctx*/) override { }
  virtual void exitAccessorFunction(MapleGrammarParser::AccessorFunctionContext * /*ctx*/) override { }

  virtual void enterLeftValue(MapleGrammarParser::LeftValueContext * /*ctx*/) override { }
  virtual void exitLeftValue(MapleGrammarParser::LeftValueContext * /*ctx*/) override { }

  virtual void enterAccessor(MapleGrammarParser::AccessorContext * /*ctx*/) override { }
  virtual void exitAccessor(MapleGrammarParser::AccessorContext * /*ctx*/) override { }

  virtual void enterIfStatement(MapleGrammarParser::IfStatementContext * /*ctx*/) override { }
  virtual void exitIfStatement(MapleGrammarParser::IfStatementContext * /*ctx*/) override { }

  virtual void enterElseStatement(MapleGrammarParser::ElseStatementContext * /*ctx*/) override { }
  virtual void exitElseStatement(MapleGrammarParser::ElseStatementContext * /*ctx*/) override { }

  virtual void enterWhileStatement(MapleGrammarParser::WhileStatementContext * /*ctx*/) override { }
  virtual void exitWhileStatement(MapleGrammarParser::WhileStatementContext * /*ctx*/) override { }

  virtual void enterFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext * /*ctx*/) override { }
  virtual void exitFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext * /*ctx*/) override { }

  virtual void enterReturnStatement(MapleGrammarParser::ReturnStatementContext * /*ctx*/) override { }
  virtual void exitReturnStatement(MapleGrammarParser::ReturnStatementContext * /*ctx*/) override { }

  virtual void enterBlockFunction(MapleGrammarParser::BlockFunctionContext * /*ctx*/) override { }
  virtual void exitBlockFunction(MapleGrammarParser::BlockFunctionContext * /*ctx*/) override { }

  virtual void enterArgumentList(MapleGrammarParser::ArgumentListContext * /*ctx*/) override { }
  virtual void exitArgumentList(MapleGrammarParser::ArgumentListContext * /*ctx*/) override { }

  virtual void enterTypeList(MapleGrammarParser::TypeListContext * /*ctx*/) override { }
  virtual void exitTypeList(MapleGrammarParser::TypeListContext * /*ctx*/) override { }

  virtual void enterBlock(MapleGrammarParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(MapleGrammarParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatement(MapleGrammarParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(MapleGrammarParser::StatementContext * /*ctx*/) override { }

  virtual void enterInstruction(MapleGrammarParser::InstructionContext * /*ctx*/) override { }
  virtual void exitInstruction(MapleGrammarParser::InstructionContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};


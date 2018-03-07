
// Generated from F:/Downloads/MapleCompiler/front-end\MapleGrammar.g4 by ANTLR 4.7

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

    virtual antlrcpp::Any visitOp1(MapleGrammarParser::Op1Context *context) = 0;

    virtual antlrcpp::Any visitOp2(MapleGrammarParser::Op2Context *context) = 0;

    virtual antlrcpp::Any visitOp3(MapleGrammarParser::Op3Context *context) = 0;

    virtual antlrcpp::Any visitOp4(MapleGrammarParser::Op4Context *context) = 0;

    virtual antlrcpp::Any visitOp5(MapleGrammarParser::Op5Context *context) = 0;

    virtual antlrcpp::Any visitOp6(MapleGrammarParser::Op6Context *context) = 0;

    virtual antlrcpp::Any visitOp7(MapleGrammarParser::Op7Context *context) = 0;

    virtual antlrcpp::Any visitOp8(MapleGrammarParser::Op8Context *context) = 0;

    virtual antlrcpp::Any visitOp9(MapleGrammarParser::Op9Context *context) = 0;

    virtual antlrcpp::Any visitOp10(MapleGrammarParser::Op10Context *context) = 0;

    virtual antlrcpp::Any visitOp11(MapleGrammarParser::Op11Context *context) = 0;

    virtual antlrcpp::Any visitOp12(MapleGrammarParser::Op12Context *context) = 0;

    virtual antlrcpp::Any visitOp13(MapleGrammarParser::Op13Context *context) = 0;

    virtual antlrcpp::Any visitExpr(MapleGrammarParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationVar(MapleGrammarParser::DeclarationVarContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationTab(MapleGrammarParser::DeclarationTabContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(MapleGrammarParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitDefinitionTab(MapleGrammarParser::DefinitionTabContext *context) = 0;

    virtual antlrcpp::Any visitAssignment(MapleGrammarParser::AssignmentContext *context) = 0;

    virtual antlrcpp::Any visitAccessorTab(MapleGrammarParser::AccessorTabContext *context) = 0;

    virtual antlrcpp::Any visitAccessorVar(MapleGrammarParser::AccessorVarContext *context) = 0;

    virtual antlrcpp::Any visitAccessorFunction(MapleGrammarParser::AccessorFunctionContext *context) = 0;

    virtual antlrcpp::Any visitLeftValue(MapleGrammarParser::LeftValueContext *context) = 0;

    virtual antlrcpp::Any visitAccessor(MapleGrammarParser::AccessorContext *context) = 0;

    virtual antlrcpp::Any visitIf(MapleGrammarParser::IfContext *context) = 0;

    virtual antlrcpp::Any visitElse(MapleGrammarParser::ElseContext *context) = 0;

    virtual antlrcpp::Any visitWhile(MapleGrammarParser::WhileContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitReturnStatement(MapleGrammarParser::ReturnStatementContext *context) = 0;

    virtual antlrcpp::Any visitBlockFunction(MapleGrammarParser::BlockFunctionContext *context) = 0;

    virtual antlrcpp::Any visitArgumentList(MapleGrammarParser::ArgumentListContext *context) = 0;

    virtual antlrcpp::Any visitTypeList(MapleGrammarParser::TypeListContext *context) = 0;

    virtual antlrcpp::Any visitBlock(MapleGrammarParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStatement(MapleGrammarParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitInstruction(MapleGrammarParser::InstructionContext *context) = 0;


};


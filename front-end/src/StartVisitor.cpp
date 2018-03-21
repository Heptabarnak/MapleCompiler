#include <expression/ExprValue.h>
#include "StartVisitor.h"

antlrcpp::Any StartVisitor::visitValue(MapleGrammarParser::ValueContext *ctx) {
    return new ExprValue(
            ctx->INTEGER()->getText(),
            ctx->CHAR()->getText()
    );
}

antlrcpp::Any StartVisitor::visitStart(MapleGrammarParser::StartContext *ctx) {
    return MapleGrammarBaseVisitor::visitStart(ctx);
}

antlrcpp::Any StartVisitor::visitProgram(MapleGrammarParser::ProgramContext *ctx) {
    return MapleGrammarBaseVisitor::visitProgram(ctx);
}

antlrcpp::Any StartVisitor::visitExprAdditive(MapleGrammarParser::ExprAdditiveContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprAdditive(ctx);
}

antlrcpp::Any StartVisitor::visitExprValue(MapleGrammarParser::ExprValueContext *ctx) {
    return visitValue(ctx->value());
}

antlrcpp::Any StartVisitor::visitExprBinaryShift(MapleGrammarParser::ExprBinaryShiftContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprBinaryShift(ctx);
}

antlrcpp::Any StartVisitor::visitExprAffectation(MapleGrammarParser::ExprAffectationContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprAffectation(ctx);
}

antlrcpp::Any StartVisitor::visitExprBinaryXor(MapleGrammarParser::ExprBinaryXorContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprBinaryXor(ctx);
}

antlrcpp::Any StartVisitor::visitExprBinaryAnd(MapleGrammarParser::ExprBinaryAndContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprBinaryAnd(ctx);
}

antlrcpp::Any StartVisitor::visitExprOr(MapleGrammarParser::ExprOrContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprOr(ctx);
}

antlrcpp::Any StartVisitor::visitExprUnaryPostfix(MapleGrammarParser::ExprUnaryPostfixContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprUnaryPostfix(ctx);
}

antlrcpp::Any StartVisitor::visitExprMultiplicative(MapleGrammarParser::ExprMultiplicativeContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprMultiplicative(ctx);
}

antlrcpp::Any StartVisitor::visitExprAccessor(MapleGrammarParser::ExprAccessorContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprAccessor(ctx);
}

antlrcpp::Any StartVisitor::visitExprAnd(MapleGrammarParser::ExprAndContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprAnd(ctx);
}

antlrcpp::Any StartVisitor::visitExprParenthesis(MapleGrammarParser::ExprParenthesisContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprParenthesis(ctx);
}

antlrcpp::Any StartVisitor::visitExprBinaryOr(MapleGrammarParser::ExprBinaryOrContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprBinaryOr(ctx);
}

antlrcpp::Any StartVisitor::visitExprCompareRelational(MapleGrammarParser::ExprCompareRelationalContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprCompareRelational(ctx);
}

antlrcpp::Any StartVisitor::visitExprCompareEquality(MapleGrammarParser::ExprCompareEqualityContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprCompareEquality(ctx);
}

antlrcpp::Any StartVisitor::visitExprUnaryPrefix(MapleGrammarParser::ExprUnaryPrefixContext *ctx) {
    return MapleGrammarBaseVisitor::visitExprUnaryPrefix(ctx);
}

antlrcpp::Any StartVisitor::visitDeclarationVar(MapleGrammarParser::DeclarationVarContext *ctx) {
    return MapleGrammarBaseVisitor::visitDeclarationVar(ctx);
}

antlrcpp::Any StartVisitor::visitDeclarationTab(MapleGrammarParser::DeclarationTabContext *ctx) {
    return MapleGrammarBaseVisitor::visitDeclarationTab(ctx);
}

antlrcpp::Any StartVisitor::visitDeclaration(MapleGrammarParser::DeclarationContext *ctx) {
    return MapleGrammarBaseVisitor::visitDeclaration(ctx);
}

antlrcpp::Any StartVisitor::visitDefinitionTab(MapleGrammarParser::DefinitionTabContext *ctx) {
    return MapleGrammarBaseVisitor::visitDefinitionTab(ctx);
}

antlrcpp::Any StartVisitor::visitAssignment(MapleGrammarParser::AssignmentContext *ctx) {
    return MapleGrammarBaseVisitor::visitAssignment(ctx);
}

antlrcpp::Any StartVisitor::visitAccessorTab(MapleGrammarParser::AccessorTabContext *ctx) {
    return MapleGrammarBaseVisitor::visitAccessorTab(ctx);
}

antlrcpp::Any StartVisitor::visitAccessorVar(MapleGrammarParser::AccessorVarContext *ctx) {
    return MapleGrammarBaseVisitor::visitAccessorVar(ctx);
}

antlrcpp::Any StartVisitor::visitAccessorFunction(MapleGrammarParser::AccessorFunctionContext *ctx) {
    return MapleGrammarBaseVisitor::visitAccessorFunction(ctx);
}

antlrcpp::Any StartVisitor::visitLeftValue(MapleGrammarParser::LeftValueContext *ctx) {
    return MapleGrammarBaseVisitor::visitLeftValue(ctx);
}

antlrcpp::Any StartVisitor::visitAccessor(MapleGrammarParser::AccessorContext *ctx) {
    return MapleGrammarBaseVisitor::visitAccessor(ctx);
}

antlrcpp::Any StartVisitor::visitIfStatement(MapleGrammarParser::IfStatementContext *ctx) {
    return MapleGrammarBaseVisitor::visitIfStatement(ctx);
}

antlrcpp::Any StartVisitor::visitElseStatement(MapleGrammarParser::ElseStatementContext *ctx) {
    return MapleGrammarBaseVisitor::visitElseStatement(ctx);
}

antlrcpp::Any StartVisitor::visitWhileStatement(MapleGrammarParser::WhileStatementContext *ctx) {
    return MapleGrammarBaseVisitor::visitWhileStatement(ctx);
}

antlrcpp::Any StartVisitor::visitFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext *ctx) {
    return MapleGrammarBaseVisitor::visitFunctionDefinition(ctx);
}

antlrcpp::Any StartVisitor::visitReturnStatement(MapleGrammarParser::ReturnStatementContext *ctx) {
    return MapleGrammarBaseVisitor::visitReturnStatement(ctx);
}

antlrcpp::Any StartVisitor::visitBlockFunction(MapleGrammarParser::BlockFunctionContext *ctx) {
    return MapleGrammarBaseVisitor::visitBlockFunction(ctx);
}

antlrcpp::Any StartVisitor::visitArgumentList(MapleGrammarParser::ArgumentListContext *ctx) {
    return MapleGrammarBaseVisitor::visitArgumentList(ctx);
}

antlrcpp::Any StartVisitor::visitTypeList(MapleGrammarParser::TypeListContext *ctx) {
    return MapleGrammarBaseVisitor::visitTypeList(ctx);
}

antlrcpp::Any StartVisitor::visitBlock(MapleGrammarParser::BlockContext *ctx) {
    return MapleGrammarBaseVisitor::visitBlock(ctx);
}

antlrcpp::Any StartVisitor::visitStatement(MapleGrammarParser::StatementContext *ctx) {
    return MapleGrammarBaseVisitor::visitStatement(ctx);
}

antlrcpp::Any StartVisitor::visitInstruction(MapleGrammarParser::InstructionContext *ctx) {
    return MapleGrammarBaseVisitor::visitInstruction(ctx);
}
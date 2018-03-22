#include <Declarations.h>
#include <mapContext2Vector.h>
#include "StartVisitor.h"

antlrcpp::Any StartVisitor::visitIfStatement(MapleGrammarParser::IfStatementContext *ctx) {
    return new IfStatement(
            visit(ctx->expr()),
            visit(ctx->instruction()),
            visit(ctx->elseStatement())
    );
}

antlrcpp::Any StartVisitor::visitElseStatement(MapleGrammarParser::ElseStatementContext *ctx) {
    return visit(ctx->instruction());
}

antlrcpp::Any StartVisitor::visitWhileStatement(MapleGrammarParser::WhileStatementContext *ctx) {
    return new WhileStatement(
            visit(ctx->expr()),
            visit(ctx->instruction())
    );
}

antlrcpp::Any StartVisitor::visitReturnStatement(MapleGrammarParser::ReturnStatementContext *ctx) {
    return new ReturnStatement(
            (Expr *) visit(ctx->expr())
    );
}

antlrcpp::Any StartVisitor::visitBlock(MapleGrammarParser::BlockContext *ctx) {
    return new Block(
            mapContext2Vector<MapleGrammarParser::InstructionContext *, Instruction *>(ctx->instruction(), this)
    );
}

antlrcpp::Any StartVisitor::visitStatement(MapleGrammarParser::StatementContext *ctx) {
    return new Statement(
            (Expr *) visit(ctx->expr())
    );
}

antlrcpp::Any StartVisitor::visitInstruction(MapleGrammarParser::InstructionContext *ctx) {
    if (ctx->statement() != nullptr) {
        return visit(ctx->statement());
    }
    if (ctx->ifStatement() != nullptr) {
        return visit(ctx->ifStatement());
    }
    if (ctx->whileStatement() != nullptr) {
        return visit(ctx->whileStatement());
    }
    if (ctx->block() != nullptr) {
        return visit(ctx->block());
    }
    return visit(ctx->returnStatement());
}
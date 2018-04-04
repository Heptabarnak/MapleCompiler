#include <Declarations.h>
#include <mapContext2Vector.h>
#include <control-structure/ForStatement.h>
#include "StartVisitor.h"

antlrcpp::Any StartVisitor::visitIfStatement(MapleGrammarParser::IfStatementContext *ctx) {

    if (ctx->elseStatement() == nullptr) {
        return (Instruction *) new IfStatement(
                visit(ctx->expr()),
                visit(ctx->instruction())
        );
    }

    return (Instruction *) new IfStatement(
            visit(ctx->expr()),
            visit(ctx->instruction()),
            visit(ctx->elseStatement())
    );
}

antlrcpp::Any StartVisitor::visitElseStatement(MapleGrammarParser::ElseStatementContext *ctx) {
    return (Instruction *) visit(ctx->instruction());
}

antlrcpp::Any StartVisitor::visitWhileStatement(MapleGrammarParser::WhileStatementContext *ctx) {
    return (Instruction *) new WhileStatement(
            visit(ctx->expr()),
            visit(ctx->instruction())
    );
}

antlrcpp::Any StartVisitor::visitReturnStatement(MapleGrammarParser::ReturnStatementContext *ctx) {
    return (Instruction *) new ReturnStatement(
            (Expr *) visit(ctx->expr())
    );
}

antlrcpp::Any StartVisitor::visitBlock(MapleGrammarParser::BlockContext *ctx) {
    return (Instruction *) new Block(
            *mapContext2Vector<MapleGrammarParser::InstructionContext *, Instruction *>(ctx->instruction(), this)
    );
}

antlrcpp::Any StartVisitor::visitStatement(MapleGrammarParser::StatementContext *ctx) {
    return (Instruction *) new Statement(
            (Expr *) visit(ctx->expr())
    );
}

antlrcpp::Any StartVisitor::visitForStatement(MapleGrammarParser::ForStatementContext *context) {
    Expr *init = nullptr;
    Expr *cond = nullptr;
    Expr *post = nullptr;
    if(context->init){
        init = visit(context->init);
    }
    if(context->cond){
        cond = visit(context->cond);
    }
    if(context->post){
        post = visit(context->post);
    }
    return (Instruction *) new ForStatement(init,
                                            cond,
                                            post,
                                            (Instruction *) visit(context->instruction())
    );
}

antlrcpp::Any StartVisitor::visitInstruction(MapleGrammarParser::InstructionContext *ctx) {
    if (ctx->statement() != nullptr) {
        return (Instruction *) visit(ctx->statement());
    }
    if (ctx->ifStatement() != nullptr) {
        return (Instruction *) visit(ctx->ifStatement());
    }
    if (ctx->whileStatement() != nullptr) {
        return (Instruction *) visit(ctx->whileStatement());
    }
    if (ctx->forStatement() != nullptr){
        return (Instruction *) visit(ctx->forStatement());
    }
    if (ctx->block() != nullptr) {
        return (Instruction *) visit(ctx->block());
    }
    return (Instruction *) visit(ctx->returnStatement());
}
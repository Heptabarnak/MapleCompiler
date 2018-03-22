#include "Declarations.h"
#include "StartVisitor.h"


antlrcpp::Any StartVisitor::visitExprValue(MapleGrammarParser::ExprValueContext *ctx) {
    return new ExprValue(
            (Value *) visit(ctx->value())
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryShift(MapleGrammarParser::ExprBinaryShiftContext *ctx) {
    return new ExprBinaryShiftOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1)),
            visit(ctx->opBinaryShift())
    );
}

antlrcpp::Any StartVisitor::visitExprAffectation(MapleGrammarParser::ExprAffectationContext *ctx) {
    return new ExprAffectation(
            visit(ctx->leftValue()),
            visit(ctx->expr()),
            visit(ctx->opAffectation())
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryXor(MapleGrammarParser::ExprBinaryXorContext *ctx) {
    return new ExprBinaryXorOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1))
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryAnd(MapleGrammarParser::ExprBinaryAndContext *ctx) {
    return new ExprBinaryAndOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1))
    );
}

antlrcpp::Any StartVisitor::visitExprOr(MapleGrammarParser::ExprOrContext *ctx) {
    return new ExprOrOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1))
    );
}

antlrcpp::Any StartVisitor::visitExprMultiplicative(MapleGrammarParser::ExprMultiplicativeContext *ctx) {
    return new ExprMultiplicativeOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1)),
            visit(ctx->opMultiplicative())
    );
}

antlrcpp::Any StartVisitor::visitExprAdditive(MapleGrammarParser::ExprAdditiveContext *ctx) {
    return new ExprAdditiveOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1)),
            visit(ctx->opAdditive())
    );
}

antlrcpp::Any StartVisitor::visitExprAccessor(MapleGrammarParser::ExprAccessorContext *ctx) {
    return new ExprAccessor(
            (Accessor *) visit(ctx->accessor())
    );
}

antlrcpp::Any StartVisitor::visitExprAnd(MapleGrammarParser::ExprAndContext *ctx) {
    return new ExprAndOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1))
    );
}

antlrcpp::Any StartVisitor::visitExprParenthesis(MapleGrammarParser::ExprParenthesisContext *ctx) {
    return new ExprParenthesis(
            (Expr *) visit(ctx->expr())
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryOr(MapleGrammarParser::ExprBinaryOrContext *ctx) {
    return new ExprBinaryOrOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1))
    );
}

antlrcpp::Any StartVisitor::visitExprCompareRelational(MapleGrammarParser::ExprCompareRelationalContext *ctx) {
    return new ExprRelationalComparisonOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1)),
            visit(ctx->opCompareRelational())
    );
}

antlrcpp::Any StartVisitor::visitExprCompareEquality(MapleGrammarParser::ExprCompareEqualityContext *ctx) {
    return new ExprEqualityComparisonOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1)),
            visit(ctx->opCompareEquality())
    );
}

antlrcpp::Any StartVisitor::visitExprUnaryPrefix(MapleGrammarParser::ExprUnaryPrefixContext *ctx) {
    return new ExprPrefixUnary(
            visit(ctx->expr()),
            visit(ctx->opUnaryPrefix())
    );
}

antlrcpp::Any StartVisitor::visitExprIncrementPostfix(MapleGrammarParser::ExprIncrementPostfixContext *ctx) {
    return new ExprIncrement(
            visit(ctx->leftValue()),
            visit(ctx->opIncrement()),
            true
    );
}

antlrcpp::Any StartVisitor::visitExprIncrementPrefix(MapleGrammarParser::ExprIncrementPrefixContext *ctx) {
    return new ExprIncrement(
            visit(ctx->leftValue()),
            visit(ctx->opIncrement()),
            false
    );
}


#include <Declarations.h>
#include "StartVisitor.h"


antlrcpp::Any StartVisitor::visitExprValue(MapleGrammarParser::ExprValueContext *ctx) {
    return (Expr *) new ExprValue(
            (Value *) visit(ctx->value())
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryShift(MapleGrammarParser::ExprBinaryShiftContext *ctx) {
    return (Expr *) new ExprBinaryShiftOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1)),
            visit(ctx->opBinaryShift())
    );
}

antlrcpp::Any StartVisitor::visitExprAffectation(MapleGrammarParser::ExprAffectationContext *ctx) {
    LeftValue *leftValue = visit(ctx->leftValue());

    if (auto symbol = currentSymbolTable->lookup(leftValue->getSymbolName())) {
        symbol->doAffectation();
    }

    return (Expr *) new ExprAffectation(
            leftValue,
            visit(ctx->expr()),
            visit(ctx->opAffectation())
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryXor(MapleGrammarParser::ExprBinaryXorContext *ctx) {
    return (Expr *) new ExprBinaryXorOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1))
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryAnd(MapleGrammarParser::ExprBinaryAndContext *ctx) {
    return (Expr *) new ExprBinaryAndOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1))
    );
}

antlrcpp::Any StartVisitor::visitExprOr(MapleGrammarParser::ExprOrContext *ctx) {
    return (Expr *) new ExprOrOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1))
    );
}

antlrcpp::Any StartVisitor::visitExprMultiplicative(MapleGrammarParser::ExprMultiplicativeContext *ctx) {
    return (Expr *) new ExprMultiplicativeOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1)),
            visit(ctx->opMultiplicative())
    );
}

antlrcpp::Any StartVisitor::visitExprAdditive(MapleGrammarParser::ExprAdditiveContext *ctx) {
    return (Expr *) new ExprAdditiveOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1)),
            visit(ctx->opAdditive())
    );
}

antlrcpp::Any StartVisitor::visitExprAccessor(MapleGrammarParser::ExprAccessorContext *ctx) {
    return (Expr *) new ExprAccessor(
            (Accessor *) visit(ctx->accessor())
    );
}

antlrcpp::Any StartVisitor::visitExprAnd(MapleGrammarParser::ExprAndContext *ctx) {
    return (Expr *) new ExprAndOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1))
    );
}

antlrcpp::Any StartVisitor::visitExprParenthesis(MapleGrammarParser::ExprParenthesisContext *ctx) {
    return (Expr *) new ExprParenthesis(
            (Expr *) visit(ctx->expr())
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryOr(MapleGrammarParser::ExprBinaryOrContext *ctx) {
    return (Expr *) new ExprBinaryOrOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1))
    );
}

antlrcpp::Any StartVisitor::visitExprCompareRelational(MapleGrammarParser::ExprCompareRelationalContext *ctx) {
    return (Expr *) new ExprRelationalComparisonOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1)),
            visit(ctx->opCompareRelational())
    );
}

antlrcpp::Any StartVisitor::visitExprCompareEquality(MapleGrammarParser::ExprCompareEqualityContext *ctx) {
    return (Expr *) new ExprEqualityComparisonOperation(
            visit(ctx->expr(0)),
            visit(ctx->expr(1)),
            visit(ctx->opCompareEquality())
    );
}

antlrcpp::Any StartVisitor::visitExprUnaryPrefix(MapleGrammarParser::ExprUnaryPrefixContext *ctx) {
    return (Expr *) new ExprPrefixUnary(
            visit(ctx->expr()),
            visit(ctx->opUnaryPrefix())
    );
}

antlrcpp::Any StartVisitor::visitExprIncrementPostfix(MapleGrammarParser::ExprIncrementPostfixContext *ctx) {
    LeftValue *leftValue = visit(ctx->leftValue());

    if (auto symbol = currentSymbolTable->lookup(leftValue->getSymbolName())) {
        symbol->doAffectation();
    }

    return (Expr *) new ExprIncrement(
            leftValue,
            visit(ctx->opIncrement()),
            true
    );
}

antlrcpp::Any StartVisitor::visitExprIncrementPrefix(MapleGrammarParser::ExprIncrementPrefixContext *ctx) {
    LeftValue *leftValue = visit(ctx->leftValue());

    if (auto symbol = currentSymbolTable->lookup(leftValue->getSymbolName())) {
        symbol->doAffectation();
    }

    return (Expr *) new ExprIncrement(
            leftValue,
            visit(ctx->opIncrement()),
            false
    );
}

antlrcpp::Any StartVisitor::visitValue(MapleGrammarParser::ValueContext *ctx) {
    if (ctx->INTEGER() == nullptr) {
        return new Value(Type::CHAR, ctx->CHAR()->getText().at(0));
    }
    return new Value(Type::INT64_T, stoi(ctx->INTEGER()->getText()));
}

StartVisitor::StartVisitor(Config *conf) : conf(conf) {}

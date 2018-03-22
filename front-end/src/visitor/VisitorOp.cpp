#include "StartVisitor.h"

antlrcpp::Any StartVisitor::visitOpIncrement(MapleGrammarParser::OpIncrementContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any StartVisitor::visitOpUnaryPrefix(MapleGrammarParser::OpUnaryPrefixContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any StartVisitor::visitOpMultiplicative(MapleGrammarParser::OpMultiplicativeContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any StartVisitor::visitOpAdditive(MapleGrammarParser::OpAdditiveContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any StartVisitor::visitOpBinaryShift(MapleGrammarParser::OpBinaryShiftContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any StartVisitor::visitOpCompareRelational(MapleGrammarParser::OpCompareRelationalContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any StartVisitor::visitOpCompareEquality(MapleGrammarParser::OpCompareEqualityContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any StartVisitor::visitOpBinaryAnd(MapleGrammarParser::OpBinaryAndContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any StartVisitor::visitOpBinaryXor(MapleGrammarParser::OpBinaryXorContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any StartVisitor::visitOpBinaryOr(MapleGrammarParser::OpBinaryOrContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any StartVisitor::visitOpAnd(MapleGrammarParser::OpAndContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any StartVisitor::visitOpOr(MapleGrammarParser::OpOrContext *ctx) {
    return ctx->getText();
}

antlrcpp::Any StartVisitor::visitOpAffectation(MapleGrammarParser::OpAffectationContext *ctx) {
    return ctx->getText();
}

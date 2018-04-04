#include <iostream>
#include <stdexcept>
#include <Declarations.h>
#include <printDebugInfo.h>
#include <expression/operation/ExprCommaOperation.h>
#include "StartVisitor.h"

using std::cerr;
using std::endl;

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
    LeftValueAccessor *leftValue = visit(ctx->leftValue());

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
    LeftValueAccessor *leftValue = visit(ctx->leftValue());

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
    LeftValueAccessor *leftValue = visit(ctx->leftValue());

    if (auto symbol = currentSymbolTable->lookup(leftValue->getSymbolName())) {
        symbol->doAffectation();
    }

    return (Expr *) new ExprIncrement(
            leftValue,
            visit(ctx->opIncrement()),
            false
    );
}

antlrcpp::Any StartVisitor::visitExprComma(MapleGrammarParser::ExprCommaContext *context) {
    return (Expr *) new ExprCommaOperation(
            visit(context->expr(0)),
            visit(context->expr(1))
            );
}

antlrcpp::Any StartVisitor::visitValue(MapleGrammarParser::ValueContext *ctx) {
    if (ctx->INTEGER() == nullptr) {
        auto val = ctx->CHAR()->getText();
        char c;

        if (val.size() > 3) {
            switch (val.at(2)) {
                case 'a':
                    c = '\a';
                    break;
                case 'b':
                    c = '\b';
                    break;
                case 't':
                    c = '\t';
                    break;
                case 'n':
                    c = '\n';
                    break;
                case 'v':
                    c = '\v';
                    break;
                case 'f':
                    c = '\f';
                    break;
                case 'r':
                    c = '\r';
                    break;
                case '"':
                    c = '\"';
                    break;
                default:
                    cerr << "Unable to parse escaped character " << val.at(2) << "!" << endl;
                    printDebugInfo(cerr, ctx);
                    throw std::runtime_error("Unable to parse escaped character");
            }
        } else {
            c = val.at(1);
        }
        return new Value(Type::CHAR, c);
    }

    return new
            Value(Type::INT64_T, stoi(ctx->INTEGER()->getText())
    );
}



#include <iostream>
#include <stdexcept>
#include <Declarations.h>
#include <printDebugInfo.h>
#include <expression/operation/ExprCommaOperation.h>
#include "StartVisitor.h"

using std::cerr;
using std::endl;

antlrcpp::Any StartVisitor::visitExprValue(MapleGrammarParser::ExprValueContext *ctx) {
    Value *value = visit(ctx->value());
    return (Expr *) new ExprValue(
            value, value->getType()
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryShift(MapleGrammarParser::ExprBinaryShiftContext *ctx) {
    Expr *expr1 = visit(ctx->expr(0));
    Expr *expr2 = visit(ctx->expr(1));

    return (Expr *) new ExprBinaryShiftOperation(
            expr1,
            expr2,
            visit(ctx->opBinaryShift()),
            std::max(expr1->getType(), expr2->getType())
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
            visit(ctx->opAffectation()),
            leftValue->getType()
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryXor(MapleGrammarParser::ExprBinaryXorContext *ctx) {
    Expr *expr1 = visit(ctx->expr(0));
    Expr *expr2 = visit(ctx->expr(1));

    return (Expr *) new ExprBinaryXorOperation(
            expr1,
            expr2,
            std::max(expr1->getType(), expr2->getType())
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryAnd(MapleGrammarParser::ExprBinaryAndContext *ctx) {
    Expr *expr1 = visit(ctx->expr(0));
    Expr *expr2 = visit(ctx->expr(1));

    return (Expr *) new ExprBinaryAndOperation(
            expr1,
            expr2,
            std::max(expr1->getType(), expr2->getType())
    );
}

antlrcpp::Any StartVisitor::visitExprOr(MapleGrammarParser::ExprOrContext *ctx) {
    Expr *expr1 = visit(ctx->expr(0));
    Expr *expr2 = visit(ctx->expr(1));
    return (Expr *) new ExprOrOperation(
            expr1,
            expr2,
            std::max(expr1->getType(), expr2->getType())

    );
}

antlrcpp::Any StartVisitor::visitExprMultiplicative(MapleGrammarParser::ExprMultiplicativeContext *ctx) {
    Expr *expr1 = visit(ctx->expr(0));
    Expr *expr2 = visit(ctx->expr(1));
    return (Expr *) new ExprMultiplicativeOperation(
            expr1,
            expr2,
            visit(ctx->opMultiplicative()),
            std::max(expr1->getType(), expr2->getType())
    );
}

antlrcpp::Any StartVisitor::visitExprAdditive(MapleGrammarParser::ExprAdditiveContext *ctx) {
    Expr *expr1 = visit(ctx->expr(0));
    Expr *expr2 = visit(ctx->expr(1));
    return (Expr *) new ExprAdditiveOperation(
            expr1,
            expr2,
            visit(ctx->opAdditive()),
            std::max(expr1->getType(), expr2->getType())
    );
}

antlrcpp::Any StartVisitor::visitExprAccessor(MapleGrammarParser::ExprAccessorContext *ctx) {
    Accessor * accessor = visit(ctx->accessor());
    return (Expr *) new ExprAccessor(
            accessor,
            accessor->getType()
    );
}

antlrcpp::Any StartVisitor::visitExprAnd(MapleGrammarParser::ExprAndContext *ctx) {
    Expr *expr1 = visit(ctx->expr(0));
    Expr *expr2 = visit(ctx->expr(1));
    return (Expr *) new ExprAndOperation(
            expr1,
            expr2,
            std::max(expr1->getType(), expr2->getType())
    );
}

antlrcpp::Any StartVisitor::visitExprParenthesis(MapleGrammarParser::ExprParenthesisContext *ctx) {
    Expr * expr = visit(ctx->possibleCommaExpr());
    return (Expr *) new ExprParenthesis(
            expr,
            expr->getType()
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryOr(MapleGrammarParser::ExprBinaryOrContext *ctx) {
    Expr *expr1 = visit(ctx->expr(0));
    Expr *expr2 = visit(ctx->expr(1));
    return (Expr *) new ExprBinaryOrOperation(
            expr1,
            expr2,
            std::max(expr1->getType(), expr2->getType())
    );
}

antlrcpp::Any StartVisitor::visitExprCompareRelational(MapleGrammarParser::ExprCompareRelationalContext *ctx) {
    Expr *expr1 = visit(ctx->expr(0));
    Expr *expr2 = visit(ctx->expr(1));
    return (Expr *) new ExprRelationalComparisonOperation(
            expr1,
            expr2,
            visit(ctx->opCompareRelational()),
            std::max(expr1->getType(), expr2->getType())
    );
}

antlrcpp::Any StartVisitor::visitExprCompareEquality(MapleGrammarParser::ExprCompareEqualityContext *ctx) {
    Expr *expr1 = visit(ctx->expr(0));
    Expr *expr2 = visit(ctx->expr(1));
    return (Expr *) new ExprEqualityComparisonOperation(
            expr1,
            expr2,
            visit(ctx->opCompareEquality()),
            std::max(expr1->getType(), expr2->getType())
    );
}

antlrcpp::Any StartVisitor::visitExprUnaryPrefix(MapleGrammarParser::ExprUnaryPrefixContext *ctx) {
    Expr *expr = visit(ctx->expr());
    return (Expr *) new ExprPrefixUnary(
            expr,
            visit(ctx->opUnaryPrefix()),
            expr->getType()
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
            true,
            leftValue->getType()
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
            false,
            leftValue->getType()
    );
}

antlrcpp::Any StartVisitor::visitExprComma(MapleGrammarParser::ExprCommaContext *context) {
    Expr *expr1 = visit(context->possibleCommaExpr());
    Expr *expr2 = visit(context->expr());
    return (Expr *) new ExprCommaOperation(
            expr1,
            expr2,
            std::max(expr1->getType(), expr2->getType())
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

antlrcpp::Any StartVisitor::visitExprNoComma(MapleGrammarParser::ExprNoCommaContext *context) {
    return (Expr *) visit(context->expr());
}




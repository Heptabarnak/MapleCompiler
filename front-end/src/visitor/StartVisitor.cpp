#include <vector>

#include "Declarations.h"
#include "StartVisitor.h"

using std::vector;


antlrcpp::Any StartVisitor::visitStart(MapleGrammarParser::StartContext *ctx) {
    currentSymbolTable = new SymbolTable();

    // TODO Add putchar & getchar

    vector<Declaration *> declarations;

    for (auto &&item : ctx->program()) {
        auto dList = (vector<Declaration *>) visit(item);

        declarations.insert(declarations.end(), dList.begin(), dList.end());
    }

    return start = new Start(declarations, currentSymbolTable);
}

antlrcpp::Any StartVisitor::visitProgram(MapleGrammarParser::ProgramContext *ctx) {
    if (ctx->declaration()) {
        return visit(ctx->declaration());
    }
    return visit(ctx->functionDefinition());
}


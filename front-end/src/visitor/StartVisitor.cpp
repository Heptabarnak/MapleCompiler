#include <vector>
#include <mapContext2Vector.h>

#include "Declarations.h"
#include "StartVisitor.h"

using std::vector;


antlrcpp::Any StartVisitor::visitStart(MapleGrammarParser::StartContext *ctx) {
    currentSymbolTable = new SymbolTable();

    FunctionDefinition *putchar = new FunctionDefinition(Type::VOID, "putchar", currentSymbolTable);
    FunctionDefinition *getchar = new FunctionDefinition(Type::CHAR, "getchar", currentSymbolTable);

    putchar->setArguments({new FunctionParam("char", Type::CHAR)});

    currentSymbolTable->insert("putchar", new Symbol(currentSymbolTable, putchar, true, true));
    currentSymbolTable->insert("getchar", new Symbol(currentSymbolTable, getchar, true, true));


    return start = new Start(
            *mapContext2VectorFlat<MapleGrammarParser::ProgramContext *, Declaration *>(ctx->program(), this),
            currentSymbolTable
    );
}

antlrcpp::Any StartVisitor::visitProgram(MapleGrammarParser::ProgramContext *ctx) {
    if (ctx->declaration()) {
        return (vector<Declaration *> *) visit(ctx->declaration());
    }
    auto functions = new vector<Declaration *>();
    functions->push_back((Declaration *) visit(ctx->functionDefinition()));
    return functions;
}


StartVisitor::StartVisitor(Config *conf) : conf(conf) {
    // Configure Expr class for optimisation

    Expr::setOptimisation(conf->optimisation);
}

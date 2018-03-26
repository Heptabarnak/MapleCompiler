#include <vector>
#include <mapContext2Vector.h>

#include "Declarations.h"
#include "StartVisitor.h"

using std::vector;


antlrcpp::Any StartVisitor::visitStart(MapleGrammarParser::StartContext *ctx) {
    currentSymbolTable = new SymbolTable();
    vector<FunctionParam*> vectorParamsPutchar;
    vectorParamsPutchar.push_back(new FunctionParam("char", INT64_T));
    vector<FunctionParam*> vectorParamsGetchar;
    FunctionDefinition* putchar = new FunctionDefinition(nullptr, INT64_T, vectorParamsPutchar, "putchar");
    FunctionDefinition* getchar = new FunctionDefinition(nullptr, INT64_T, vectorParamsGetchar, "getchar");

    auto symbolPutchar = new Symbol(currentSymbolTable, putchar, true, true);
    auto symbolGetchar = new Symbol(currentSymbolTable, getchar, true, true);

    currentSymbolTable->insert("putchar", symbolPutchar);
    currentSymbolTable->insert("getchar", symbolGetchar);

    return start = new Start(
            *mapContext2VectorFlat<MapleGrammarParser::ProgramContext *, Declaration *>(ctx->program(), this),
            currentSymbolTable
    );
}

antlrcpp::Any StartVisitor::visitProgram(MapleGrammarParser::ProgramContext *ctx) {
    if (ctx->declaration()) {
        return (vector<Declaration *> *) visit(ctx->declaration());
    }
    auto functions = new vector<Declaration *>(1);
    functions->push_back((Declaration *) visit(ctx->functionDefinition()));
    return functions;
}


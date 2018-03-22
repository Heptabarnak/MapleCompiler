#include <iostream>
#include <Declarations.h>
#include <mapContext2Vector.h>
#include <typeHelper.h>

#include "StartVisitor.h"


using std::cerr;
using std::endl;

antlrcpp::Any StartVisitor::visitArgumentList(MapleGrammarParser::ArgumentListContext *ctx) {
    return mapContext2Vector<MapleGrammarParser::ExprContext *, Expr *>(ctx->expr(), this);
}


antlrcpp::Any StartVisitor::visitFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext *ctx) {
    vector<FunctionParam *> fParams;

    if (ctx->typeList() != nullptr) {
        fParams = (vector<FunctionParam *>) visit(ctx->typeList());
    }

    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        // TODO Throw error, duplicate definition
        cerr << "Duplicate declaration of " << name << endl;
        cerr << "Found : " << symbol->getDeclaration() << endl;
        return nullptr;
    }

    FunctionDefinition *functionDefinition = new FunctionDefinition(
            (BlockFunction *) visit(ctx->blockFunction()),
            getTypeFromString(ctx->TYPE()->getText()),
            fParams,
            name
    );

    currentSymbolTable->insert(name, new Symbol(currentSymbolTable, functionDefinition));

    return functionDefinition;
}

antlrcpp::Any StartVisitor::visitTypeList(MapleGrammarParser::TypeListContext *ctx) {
    vector<FunctionParam *> fParams;
    for (std::size_t i = 0; i != ctx->ID().size(); i++) {
        fParams.push_back(new FunctionParam(
                ctx->ID(i)->getText(),
                getTypeFromString(ctx->TYPE(i)->getText()))
        );
    }
    return fParams;
}

antlrcpp::Any StartVisitor::visitBlockFunction(MapleGrammarParser::BlockFunctionContext *ctx) {
    currentSymbolTable = new SymbolTable(currentSymbolTable);

    auto block = new BlockFunction(
            mapContext2Vector<MapleGrammarParser::DeclarationContext *, Declaration *>(ctx->declaration(), this),
            mapContext2Vector<MapleGrammarParser::InstructionContext *, Instruction *>(ctx->instruction(), this),
            currentSymbolTable
    );

    currentSymbolTable = currentSymbolTable->getFather();
    return block;
}

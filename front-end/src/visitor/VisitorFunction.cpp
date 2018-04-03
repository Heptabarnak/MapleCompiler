#include <iostream>
#include <Declarations.h>
#include <mapContext2Vector.h>
#include <typeHelper.h>
#include <printDebugInfo.h>
#include <function/FunctionParamTab.h>

#include "StartVisitor.h"


using std::string;
using std::vector;
using std::cerr;
using std::endl;

antlrcpp::Any StartVisitor::visitArgumentList(MapleGrammarParser::ArgumentListContext *ctx) {
    return *mapContext2Vector<MapleGrammarParser::ExprContext *, Expr *>(ctx->expr(), this);
}


antlrcpp::Any StartVisitor::visitFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext *ctx) {
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        cerr << "Duplicate declaration of " << name << endl;
        cerr << "Found : " << symbol->getDeclaration() << endl;
        printDebugInfo(cerr, ctx);
        throw std::runtime_error("Duplicate definition");
    }


    Type type = Type::VOID;

    if (ctx->TYPE() != nullptr) {
        type = getTypeFromString(ctx->TYPE()->getText());
    }


    auto fDef = new FunctionDefinition(
            type,
            name
    );
    currentSymbolTable->insert(name, new Symbol(currentSymbolTable, fDef, true));


    // Add a new scoped env
    currentSymbolTable = new SymbolTable(currentSymbolTable);

    fDef->setSymbolTable(currentSymbolTable);

    if (ctx->typeList() != nullptr) {
        fDef->setArguments(*(vector<FunctionParam *> *) visit(ctx->typeList()));
    }

    fDef->setBlockFunction((BlockFunction *) visit(ctx->blockFunction()));

    currentSymbolTable = currentSymbolTable->getFather();
    // Close scoped env

    return (Declaration *) fDef;
}

antlrcpp::Any StartVisitor::visitTypeList(MapleGrammarParser::TypeListContext *ctx) {
    auto fParams = new vector<FunctionParam *>();

    for (std::size_t i = 0; i != ctx->argumentTypeVar().size(); i++) {

        auto fParam = (FunctionParam*) visit(ctx->argumentTypeVar(i));

        fParams->push_back(fParam);
    }

    for (std::size_t i = 0; i != ctx->argumentTypeArray().size(); i++) {

        auto fParamTab = (FunctionParamTab*) visit(ctx->argumentTypeArray(i));

        fParams->push_back(fParamTab);
    }
    return fParams;
}

antlrcpp::Any StartVisitor::visitArgumentTypeVar(MapleGrammarParser::ArgumentTypeVarContext *ctx) {

    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        cerr << "Duplicate declaration of " << name << endl;
        cerr << "Found : " << symbol->getDeclaration() << endl;
        printDebugInfo(cerr, ctx);
        throw std::runtime_error("Duplicated declaration");
    }

    auto fParam = new FunctionParam(
            name,
            getTypeFromString(ctx->TYPE()->getText())
    );

    currentSymbolTable->insert(name, new Symbol(currentSymbolTable, fParam, true));

    return fParam;
}

antlrcpp::Any StartVisitor::visitArgumentTypeArray(MapleGrammarParser::ArgumentTypeArrayContext *ctx) {
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        cerr << "Duplicate declaration of " << name << endl;
        cerr << "Found : " << symbol->getDeclaration() << endl;
        printDebugInfo(cerr, ctx);
        throw std::runtime_error("Duplicated declaration");
    }

    auto fParam = new FunctionParamTab(
            name,
            getTypeFromString(ctx->TYPE()->getText()),
            (int) ctx->INTEGER()
    );

    currentSymbolTable->insert(name, new Symbol(currentSymbolTable, fParam, true));

    return fParam;
}

antlrcpp::Any StartVisitor::visitBlockFunction(MapleGrammarParser::BlockFunctionContext *ctx) {
    auto block = new BlockFunction(
            *mapContext2VectorFlat<MapleGrammarParser::DeclarationContext *, Declaration *>(ctx->declaration(), this),
            *mapContext2Vector<MapleGrammarParser::InstructionContext *, Instruction *>(ctx->instruction(), this)
    );

    return block;
}

#include <string>
#include <iostream>
#include <vector>

#include <Declarations.h>
#include <typeHelper.h>
#include <mapContext2Vector.h>

#include "StartVisitor.h"

using std::cerr;
using std::endl;
using std::string;
using std::vector;


antlrcpp::Any StartVisitor::visitDeclarationTab(MapleGrammarParser::DeclarationTabContext *ctx) {
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        cerr << "Duplicate declaration of " << name << endl;
        cerr << "Found : " << symbol->getDeclaration() << endl;
        throw std::runtime_error("Duplicate definition");
    }

    if (ctx->expr() == nullptr) {
        vector<Value *> tabList = visit(ctx->definitionTab());

        Declaration *declaration = new TabDeclaration(
                getTypeFromString(ctx->TYPE()->getText()),
                tabList.size(),
                name,
                tabList
        );

        currentSymbolTable->insert(name, new Symbol(currentSymbolTable, declaration));
        return declaration;
    }

    Expr *expr = visit(ctx->expr()); // FIXME Delete expression

    if (!expr->isSimplifiable()) {
        cerr << "Unable to simplify expression for " << name << endl;
        throw std::runtime_error("Not simplifiable declaration");
    }

    const long tabSize = expr->simplify();

    if (tabSize < 1) {
        cerr << "Array size must be more than 0, got : " << tabSize << endl;
        throw std::runtime_error("Array size must > 1");
    }


    Declaration *declaration = new TabDeclaration(
            getTypeFromString(ctx->TYPE()->getText()),
            (unsigned long) tabSize,
            name
    );

    currentSymbolTable->insert(name, new Symbol(currentSymbolTable, declaration));
    return declaration;
}

antlrcpp::Any StartVisitor::visitDeclaration(MapleGrammarParser::DeclarationContext *ctx) {
    if (ctx->declarationVar()) {
        return (vector<Declaration *> *) visit(ctx->declarationVar());
    }
    auto declarations = new vector<Declaration *>(1);
    declarations->push_back((Declaration *) visit(ctx->declarationTab()));
    return declarations;
}

antlrcpp::Any StartVisitor::visitDefinitionTab(MapleGrammarParser::DefinitionTabContext *ctx) {
    return mapContext2Vector<MapleGrammarParser::ValueContext *, Value *>(ctx->value(), this);
}


antlrcpp::Any
StartVisitor::visitDeclarationVarDefinition(MapleGrammarParser::DeclarationVarDefinitionContext *ctx) {
    Type type = getTypeFromString(
            ((MapleGrammarParser::DeclarationVarContext *) ctx->parent)->TYPE()->getText()
    );

    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        cerr << "Duplicate declaration of " << name << endl;
        cerr << "Found : " << symbol->getDeclaration() << endl;
        throw std::runtime_error("Duplicated declaration");
    }

    if (ctx->assignment() == nullptr) {
        auto declaration = new VarDeclaration(name, type);

        currentSymbolTable->insert(name, new Symbol(currentSymbolTable, declaration));
        return declaration;
    }

    auto declaration = new VarDeclaration(
            name,
            type,
            visit(ctx->assignment())
    );
    currentSymbolTable->insert(name, new Symbol(currentSymbolTable, declaration, true));
    return declaration;
}


antlrcpp::Any StartVisitor::visitDeclarationVar(MapleGrammarParser::DeclarationVarContext *ctx) {
    const auto &definitions = ctx->declarationVarDefinition();
    auto declarations = new vector<Declaration *>(definitions.size());

    for (auto &&declaration : definitions) {
        declarations->push_back((VarDeclaration *) visit(declaration));
    }

    return declarations;
}


antlrcpp::Any StartVisitor::visitAssignment(MapleGrammarParser::AssignmentContext *ctx) {
    return (Expr *) visit(ctx->expr());
}

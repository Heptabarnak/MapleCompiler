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
        // TODO Throw error, duplicate definition
        cerr << "Duplicate declaration of " << name << endl;
        cerr << "Found : " << symbol->getDeclaration() << endl;
        return nullptr;
    }

    if (ctx->expr() == nullptr) {
        vector<Value *> tabList = visit(ctx->definitionTab());

        return new TabDeclaration(
                getTypeFromString(ctx->TYPE()->getText()),
                tabList.size(),
                name,
                tabList
        );
    }

    Expr *expr = visit(ctx->expr()); // FIXME Delete expression

    if (!expr->isSimplifiable()) {
        // TODO Throw error, not simplifiable expression
        cerr << "Unable to simplify expression for " << name << endl;
        return nullptr;
    }

    const long tabSize = expr->simplify();

    if (tabSize < 1) {
        // TODO Throw error, size < 1
        cerr << "Array size must be more than 0, got : " << tabSize << endl;
        return nullptr;
    }

    return new TabDeclaration(
            getTypeFromString(ctx->TYPE()->getText()),
            (unsigned long) tabSize,
            name
    );
}

antlrcpp::Any StartVisitor::visitDeclaration(MapleGrammarParser::DeclarationContext *ctx) {
    if (ctx->declarationVar()) {
        return visit(ctx->declarationVar());
    }
    vector<Declaration *> declarations(1);
    declarations.push_back((Declaration *&&) visit(ctx->declarationTab()));
    return declarations;
}

antlrcpp::Any StartVisitor::visitDefinitionTab(MapleGrammarParser::DefinitionTabContext *ctx) {
    return mapContext2Vector<MapleGrammarParser::ValueContext *, Value *>(ctx->value(), this);
}


antlrcpp::Any
StartVisitor::visitDeclarationVarDefinition(MapleGrammarParser::DeclarationVarDefinitionContext *ctx) {
    return antlrcpp::Any();
}

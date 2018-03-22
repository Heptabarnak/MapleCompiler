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
    unsigned long tabSize;
    vector<Value *> tabList = nullptr;

    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        // TODO Throw error, duplicate definition
        cerr << "Duplicate declaration of " << name << endl;
        cerr << "Found : " << symbol->getDeclaration() << endl;
        return nullptr;
    }

    if (ctx->expr() == nullptr) {
        tabList = visit(ctx->definitionTab());
        tabSize = tabList.size();
    } else {
        // FIXME Ça ne marchera pas, il faut trouver de déterminer la taille directement,
        // mais être sur que l'expression n'implique pas de variable !
        tabSize = (unsigned long) visit(ctx->expr());
    }


    return new TabDeclaration(
            getTypeFromString(ctx->TYPE()->getText()),
            tabSize,
            name,
            tabList
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

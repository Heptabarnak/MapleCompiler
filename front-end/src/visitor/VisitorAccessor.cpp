#include <iostream>
#include <string>
#include <Declarations.h>

#include "StartVisitor.h"

using std::string;
using std::cerr;
using std::endl;

antlrcpp::Any StartVisitor::visitAccessor(MapleGrammarParser::AccessorContext *ctx) {
    if (ctx->accessorFunction() == nullptr) {
        return new LeftValueAccessor((LeftValue *) (visit(ctx->leftValue())));
    }
    return new FunctionAccessor((AccessorFunction *) (visit(ctx->accessorFunction())));
}

antlrcpp::Any StartVisitor::visitAccessorTab(MapleGrammarParser::AccessorTabContext *ctx) {
    // We should note that we could allow access to a variable as an array is technically a variable !
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        if (auto symbolTab = dynamic_cast<TabDeclaration*>(symbol->getDeclaration())) {

            return new TabAccessor(
                    symbolTab,
                    visit(ctx->expr())
            );
        }

        // TODO Throw error, symbol is not an array
        cerr << "Wanted array but got :" << symbol->getDeclaration() << endl;
    } else {
        // TODO Throw error, variable not found
        cerr << "Symbol '" << name << "' was not found" << endl;
    }
    return nullptr;
}

antlrcpp::Any StartVisitor::visitAccessorVar(MapleGrammarParser::AccessorVarContext *ctx) {
    // We should note that we could allow access to an array as its not far from a variable !
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        if (auto symbolVar = dynamic_cast<VarDeclaration *>(symbol->getDeclaration())) {

            return new VarAccessor(symbolVar);
        }

        // TODO Throw error, symbol is not a variable
        cerr << "Wanted a variable but got :" << symbol->getDeclaration() << endl;
    } else {
        // TODO Throw error, variable not found
        cerr << "Symbol '" << name << "' was not found" << endl;
    }
    return nullptr;
}

antlrcpp::Any StartVisitor::visitAccessorFunction(MapleGrammarParser::AccessorFunctionContext *ctx) {
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        if (auto symbolFun = dynamic_cast<FunctionDefinition *>(symbol->getDeclaration())) {

            return new AccessorFunction(
                    symbolFun,
                    visit(ctx->argumentList())
            );
        }

        // TODO Throw error, symbol is not a function
        cerr << "Wanted a function but got :" << symbol->getDeclaration() << endl;
    } else {
        // TODO Throw error, function not found
        cerr << "Symbol '" << name << "' was not found" << endl;
    }
    return nullptr;
}

antlrcpp::Any StartVisitor::visitLeftValue(MapleGrammarParser::LeftValueContext *ctx) {
    if (ctx->accessorTab() == nullptr) {
        return new LeftValueVar((VarAccessor *) visit(ctx->accessorVar()));
    }
    return new LeftValueTab((TabAccessor *) visit(ctx->accessorTab()));
}
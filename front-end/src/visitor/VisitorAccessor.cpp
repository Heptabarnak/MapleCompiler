#include <iostream>
#include <string>
#include <Declarations.h>

#include "StartVisitor.h"

using std::string;
using std::cerr;
using std::endl;

antlrcpp::Any StartVisitor::visitAccessor(MapleGrammarParser::AccessorContext *ctx) {
    if (ctx->accessorFunction() == nullptr) {
        return (Accessor *) new LeftValueAccessor((LeftValue *) (visit(ctx->leftValue())));
    }
    return (Accessor *) new FunctionAccessor((AccessorFunction *) (visit(ctx->accessorFunction())));
}

antlrcpp::Any StartVisitor::visitAccessorTab(MapleGrammarParser::AccessorTabContext *ctx) {
    // We should note that we could allow access to a variable as an array is technically a variable !
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        if (auto symbolTab = dynamic_cast<TabDeclaration *>(symbol->getDeclaration())) {

            // TODO Check if it's reading or affectation (with parent ?)
            symbol->doRead();
            return new TabAccessor(
                    symbolTab,
                    visit(ctx->expr())
            );
        }

        cerr << "Wanted array but got :" << symbol->getDeclaration() << endl;
        throw std::runtime_error("Symbol is not an array");
    } else {
        cerr << "Symbol '" << name << "' was not found" << endl;
        throw std::runtime_error("Array not found");
    }
}

antlrcpp::Any StartVisitor::visitAccessorVar(MapleGrammarParser::AccessorVarContext *ctx) {
    // We should note that we could allow access to an array as its not far from a variable !
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        if (auto symbolVar = dynamic_cast<VarDeclaration *>(symbol->getDeclaration())) {

            // TODO Check if it's reading or affectation (with parent ?)
            symbol->doRead();
            return new VarAccessor(symbolVar);
        }

        cerr << "Wanted a variable but got :" << symbol->getDeclaration() << endl;
        throw std::runtime_error("Symbol is not a variable");
    } else {
        cerr << "Symbol '" << name << "' was not found" << endl;
        throw std::runtime_error("Variable not found");
    }
}

antlrcpp::Any StartVisitor::visitAccessorFunction(MapleGrammarParser::AccessorFunctionContext *ctx) {
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        if (auto symbolFun = dynamic_cast<FunctionDefinition *>(symbol->getDeclaration())) {

            symbol->doRead();
            return (Accessor *) new AccessorFunction(
                    symbolFun,
                    visit(ctx->argumentList())
            );
        }

        cerr << "Wanted a function but got :" << symbol->getDeclaration() << endl;
        throw std::runtime_error("Symbol is not a function");
    } else {
        cerr << "Symbol '" << name << "' was not found" << endl;
        throw std::runtime_error("Function not found");
    }
}

antlrcpp::Any StartVisitor::visitLeftValue(MapleGrammarParser::LeftValueContext *ctx) {
    if (ctx->accessorTab() == nullptr) {
        return (LeftValue *) new LeftValueVar((VarAccessor *) visit(ctx->accessorVar()));
    }
    return (LeftValue *) new LeftValueTab((TabAccessor *) visit(ctx->accessorTab()));
}
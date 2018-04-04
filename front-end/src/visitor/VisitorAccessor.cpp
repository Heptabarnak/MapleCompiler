#include <iostream>
#include <string>
#include <Declarations.h>
#include <printDebugInfo.h>

#include "StartVisitor.h"

using std::string;
using std::vector;
using std::cerr;
using std::cout;
using std::endl;

antlrcpp::Any StartVisitor::visitAccessor(MapleGrammarParser::AccessorContext *ctx) {
    Accessor *accessor = nullptr;

    if (ctx->accessorFunction() == nullptr) {
        accessor = (LeftValueAccessor *) visit(ctx->leftValue());
    } else {
        accessor = visit(ctx->accessorFunction());
    }

    const string &name = accessor->getSymbolName();
    if (auto symbol = currentSymbolTable->lookup(name)) {
        symbol->doRead();

        if (conf->staticAnalysis && !symbol->getAffectation()) {
            cout << "Warning : " << endl
                 << "\tSymbol '" << name << "' used before affectation" << endl;
            printDebugInfo(cout, ctx);
        }
    }
    return accessor;
}

antlrcpp::Any StartVisitor::visitAccessorTab(MapleGrammarParser::AccessorTabContext *ctx) {
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        if (auto symbolTab = dynamic_cast<TabDeclaration *>(symbol->getDeclaration())) {
            return (LeftValueAccessor *) new TabAccessor(
                    symbolTab,
                    visit(ctx->possibleCommaExpr())
            );
        }
        cerr << "Wanted array but got :" << symbol->getDeclaration() << endl;
        printDebugInfo(cerr, ctx);
        throw std::runtime_error("Symbol is not an array");
    } else {
        cerr << "Symbol '" << name << "' was not found" << endl;
        printDebugInfo(cerr, ctx);
        throw std::runtime_error("Array not found");
    }
}

antlrcpp::Any StartVisitor::visitAccessorVar(MapleGrammarParser::AccessorVarContext *ctx) {
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        if (auto symbolVar = dynamic_cast<VarDeclaration *>(symbol->getDeclaration())) {
            return (LeftValueAccessor *) new VarAccessor(symbolVar);
        } else if (auto symbolTab = dynamic_cast<TabDeclaration *>(symbol->getDeclaration())) {
            return (LeftValueAccessor *) new TabAccessor(symbolTab);
        }

        cerr << "Wanted a variable but got :" << symbol->getDeclaration() << endl;
        printDebugInfo(cerr, ctx);
        throw std::runtime_error("Symbol is not a variable");
    } else {
        cerr << "Symbol '" << name << "' was not found" << endl;
        printDebugInfo(cerr, ctx);
        throw std::runtime_error("Variable not found");
    }
}

antlrcpp::Any StartVisitor::visitAccessorFunction(MapleGrammarParser::AccessorFunctionContext *ctx) {
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        if (auto symbolFun = dynamic_cast<FunctionDefinition *>(symbol->getDeclaration())) {

            auto args = (vector<Expr *> *) visit(ctx->argumentList());
            if (args->size() < symbolFun->getParams()->size()) {
                cerr << "Too few arguments" << endl;
                cerr << "Found : " << args->size() << endl;
                cerr << "Expected : " << symbolFun->getParams()->size() << endl;
                printDebugInfo(cerr, ctx);
                throw std::runtime_error("Different numbers of arguments");
            }
            if (args->size() > symbolFun->getParams()->size()) {
                cerr << "Too much arguments" << endl;
                cerr << "Found : " << args->size() << endl;
                cerr << "Expected : " << symbolFun->getParams()->size() << endl;
                printDebugInfo(cerr, ctx);
                throw std::runtime_error("Different numbers of arguments");
            }

            symbol->doRead();
            return (Accessor *) new AccessorFunction(
                    symbolFun,
                    visit(ctx->argumentList())
            );
        }

        cerr << "Wanted a function but got :" << symbol->getDeclaration() << endl;
        printDebugInfo(cerr, ctx);
        throw std::runtime_error("Symbol is not a function");
    } else {
        cerr << "Symbol '" << name << "' was not found" << endl;
        printDebugInfo(cerr, ctx);
        throw std::runtime_error("Function not found");
    }
}

antlrcpp::Any StartVisitor::visitLeftValue(MapleGrammarParser::LeftValueContext *ctx) {
    if (ctx->accessorTab() == nullptr) {
        return (LeftValueAccessor *) visit(ctx->accessorVar());
    }
    return (LeftValueAccessor *) visit(ctx->accessorTab());
}

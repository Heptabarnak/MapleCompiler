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
        accessor = new LeftValueAccessor((LeftValue *) (visit(ctx->leftValue())));
    } else {
        accessor = new FunctionAccessor((AccessorFunction *) (visit(ctx->accessorFunction())));
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
    // We should note that we could allow access to a variable as an array is technically a variable !
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        if (auto symbolTab = dynamic_cast<TabDeclaration *>(symbol->getDeclaration())) {
            return new TabAccessor(
                    symbolTab,
                    visit(ctx->expr())
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
    // We should note that we could allow access to an array as its not far from a variable !
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        if (auto symbolVar = dynamic_cast<VarDeclaration *>(symbol->getDeclaration())) {
            return new VarAccessor(symbolVar);
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

            vector<FunctionParam*> argument = visit(ctx->argumentList());
            if (argument.size() < symbolFun->getParams().size()) {
                cerr << "Too few arguments" << endl;
                cerr << "Found : " << argument.size() << endl;
                cerr << "Expected : " << symbolFun->getParams().size() << endl;
                printDebugInfo(cerr, ctx);
                throw std::runtime_error("Differents numbers of arguments");
            }
            if (argument.size() > symbolFun->getParams().size()) {
                cerr << "Too much arguments" << endl;
                cerr << "Found : " << argument.size() << endl;
                cerr << "Expected : " << symbolFun->getParams().size() << endl;
                printDebugInfo(cerr, ctx);
                throw std::runtime_error("Differents numbers of arguments");
            }

            for (auto it = argument.begin(); it != argument.end(); ++it){
                if ((*it)->getType() != symbolFun->getParams().(*it)->getType()){
                    cerr << "Parameter does not have the same type as Function Definition" << endl;
                    cerr << "Found : " << (*it)->getType() << endl;
                    cerr << "Expected : " << symbolFun->getParams().(*it)->getType() << endl;
                }
            }
            symbol->doRead();
            return new AccessorFunction(
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
        return (LeftValue *) new LeftValueVar((VarAccessor *) visit(ctx->accessorVar()));
    }
    return (LeftValue *) new LeftValueTab((TabAccessor *) visit(ctx->accessorTab()));
}

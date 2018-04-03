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
using std::cout;
using std::endl;

antlrcpp::Any StartVisitor::visitArgumentList(MapleGrammarParser::ArgumentListContext *ctx) {
    return *mapContext2Vector<MapleGrammarParser::ExprContext *, Expr *>(ctx->expr(), this);
}


antlrcpp::Any StartVisitor::visitFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext *ctx) {
    const string &name = ctx->ID()->getText();

    Type type = Type::VOID;

    if (ctx->TYPE() != nullptr) {
        type = getTypeFromString(ctx->TYPE()->getText());
    }

    auto fDef = new FunctionDefinition(
            type,
            name
    );

    auto params = new vector<FunctionParam *>();

    if (ctx->typeList() != nullptr) {
        delete params;
        params = (vector<FunctionParam *> *) visit(ctx->typeList());
    }

    if (auto symbol = currentSymbolTable->lookup(name)) {
        auto decl = dynamic_cast<FunctionDefinition *> (symbol->getDeclaration());

        if (decl == nullptr || decl->getBlock() != nullptr) {
            cerr << "Duplicate definition of " << name << endl;
            printDebugInfo(cerr, ctx);
            throw std::runtime_error("Duplicate definition");
        }

        if (type != decl->getType()) {
            cerr << "Function definition does not return the same type as the declaration: " << name << endl;
            printDebugInfo(cerr, ctx);
            throw std::runtime_error("Different return type");
        }

        if (decl->getParams()->size() != params->size()) {
            cerr << "Function definition has not the same number of arguments as Function declaration " << endl;
            cerr << "Found : " << params->size() << endl;
            cerr << "Expected : " << decl->getParams()->size() << endl;
            printDebugInfo(cerr, ctx);
            throw std::runtime_error("Different number of arguments");
        }

        unsigned long i = 0;
        for (auto &&param : *params) {
            if (param->getType() != decl->getParams()->at(i)->getType()) {
                cerr << "Parameter " << param->getName()
                     << " in function definition has not the same type as in function declaration" << endl;
                cerr << "Found : " << param->getType() << endl;
                cerr << "Expected : " << decl->getParams()->at(i)->getType() << endl;
                printDebugInfo(cerr, ctx);
                throw std::runtime_error("Different type of arguments");
            }
            i++;
        }

        delete fDef;
        delete decl->getParams();
        fDef = decl;
    }

    currentSymbolTable->insert(name, new Symbol(currentSymbolTable, fDef, true));


    // Add a new scoped env
    currentSymbolTable = new SymbolTable(currentSymbolTable);

    fDef->setSymbolTable(currentSymbolTable);

    fDef->setArguments(params);

    fDef->setBlockFunction((BlockFunction *) visit(ctx->blockFunction()));

    currentSymbolTable = currentSymbolTable->getFather();
    // Close scoped env

    return (Declaration *) fDef;
}

antlrcpp::Any StartVisitor::visitFunctionDeclaration(MapleGrammarParser::FunctionDeclarationContext *ctx) {
    const string &name = ctx->ID()->getText();

    Type type = Type::VOID;

    if (ctx->TYPE() != nullptr) {
        type = getTypeFromString(ctx->TYPE()->getText());
    }

    auto fDef = new FunctionDefinition(
            type,
            name
    );

    auto params = new vector<FunctionParam *>();

    if (ctx->typeListWithoutName() != nullptr) {
        delete params;
        params = (vector<FunctionParam *> *) visit(ctx->typeListWithoutName());
        fDef->setArguments(params);
    }

    if (auto symbol = currentSymbolTable->lookup(name)) {
        auto def = dynamic_cast<FunctionDefinition *> (symbol->getDeclaration());

        if (def == nullptr) {
            cerr << "Duplicate declaration of " << name << endl;
            cerr << "Found : " << symbol->getDeclaration() << endl;
            printDebugInfo(cerr, ctx);
            throw std::runtime_error("Duplicate declaration");
        }

        if (type != def->getType()) {
            cerr << "Function declaration does not return the same type as the definition: " << name << endl;
            printDebugInfo(cerr, ctx);
            throw std::runtime_error("Different return type");
        }

        if (def->getBlock() != nullptr) {
            cout << "Warning: Function '" << name << "' is already declared, this declaration will be skipped" << endl;
            printDebugInfo(cout, ctx);
            return nullptr;
        }

        if (def->getParams()->size() != params->size()) {
            cerr << "Function declaration has not the same number of arguments as Function definition " << endl;
            cerr << "Found : " << params->size() << endl;
            cerr << "Expected : " << def->getParams()->size() << endl;
            printDebugInfo(cerr, ctx);
            throw std::runtime_error("Different number of arguments");
        }

        unsigned long i = 0;

        for (auto &&param : *params) {
            if (param->getType() != def->getParams()->at(i)->getType()) {
                cerr << "Parameter " << param->getName()
                     << " in function declaration has not the same type as in function definition" << endl;
                cerr << "Found : " << param->getType() << endl;
                cerr << "Expected : " << def->getParams()->at(i)->getType() << endl;
                printDebugInfo(cerr, ctx);
                throw std::runtime_error("Different type of arguments");
            }
            i++;
        }
        delete fDef;
        fDef = def;
    }

    currentSymbolTable->insert(name, new Symbol(currentSymbolTable, fDef, true));

    return nullptr;
}

antlrcpp::Any StartVisitor::visitTypeList(MapleGrammarParser::TypeListContext *ctx) {
    auto fParams = new vector<FunctionParam *>;

    for (auto &&item : ctx->argumentType()) {
        fParams->push_back((FunctionParam *) visit(item));
    }

    return fParams;
}

antlrcpp::Any StartVisitor::visitArgumentType(MapleGrammarParser::ArgumentTypeContext *ctx) {

    if (ctx->argumentTypeVar()) {
        return (FunctionParam *) visit(ctx->argumentTypeVar());
    }

    return (FunctionParam *) visit(ctx->argumentTypeArray());
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

antlrcpp::Any StartVisitor::visitTypeListWithoutName(MapleGrammarParser::TypeListWithoutNameContext *ctx) {
    auto fParams = new vector<FunctionParam *>();

    for (auto &&type :ctx->TYPE()) {
        fParams->push_back(new FunctionParam(
                getTypeFromString(type->getText())
        ));
    }

    return fParams;
}

antlrcpp::Any StartVisitor::visitBlockFunction(MapleGrammarParser::BlockFunctionContext *ctx) {
    auto block = new BlockFunction(
            *mapContext2VectorFlat<MapleGrammarParser::DeclarationContext *, Declaration *>(ctx->declaration(), this),
            *mapContext2Vector<MapleGrammarParser::InstructionContext *, Instruction *>(ctx->instruction(), this)
    );

    return block;
}

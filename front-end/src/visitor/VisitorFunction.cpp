#include <iostream>
#include <Declarations.h>
#include <mapContext2Vector.h>
#include <typeHelper.h>
#include <printDebugInfo.h>

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

    Type type = Type::VOID;

    if (ctx->TYPE() != nullptr) {
        type = getTypeFromString(ctx->TYPE()->getText());
    }

    auto fDef = new FunctionDefinition(
            type,
            name
    );

    vector<FunctionParam *> params;

    if(ctx->typeList()!= nullptr) {
        params = *(vector<FunctionParam *> *) visit(ctx->typeList());
    }

    if (auto symbol = currentSymbolTable->lookup(name)) {
        auto *temp = dynamic_cast<FunctionDefinition*> (symbol->getDeclaration());
        if ( temp== nullptr || temp->getBlock()!= nullptr) {
            cerr << "Duplicate declaration of " << name << endl;
            cerr << "Found : " << symbol->getDeclaration() << endl;
            printDebugInfo(cerr, ctx);
            throw std::runtime_error("Duplicate definition");
        }
        if (temp->getParams().size() != params.size()) {
            cerr << "Function definition has not the same number of arguments as Function declaration " << endl;
            cerr << "Found : " << params.size() << endl;
            cerr << "Expected : " << temp->getParams().size() << endl;
            printDebugInfo(cerr, ctx);
            throw std::runtime_error("Different number of arguments");
        }
        int i=0;
        for (auto &&param : params) {
            if(param->getType() != temp->getParams().at(i)->getType()){
                cerr << "Parameter "<< param->getName() <<" in function definition has not the same type as in function declaration" << endl;
                cerr << "Found : " << param->getType() << endl;
                cerr << "Expected : " << temp->getParams().at(i)->getType() << endl;
                printDebugInfo(cerr, ctx);
                throw std::runtime_error("Different type of arguments");
            }
            i++;
        }
        fDef = temp;
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

    vector<FunctionParam *> params;

    if(ctx->typeListWithoutName()!= nullptr) {
        params = *(vector<FunctionParam *> *) visit(ctx->typeListWithoutName());
    }

    if (auto symbol = currentSymbolTable->lookup(name)) {
        FunctionDefinition *temp = dynamic_cast<FunctionDefinition*> (symbol->getDeclaration());
        if ( temp== nullptr) {
            cerr << "Duplicate declaration of " << name << endl;
            cerr << "Found : " << symbol->getDeclaration() << endl;
            printDebugInfo(cerr, ctx);
            throw std::runtime_error("Duplicate definition");
        }
        if (auto block = temp->getBlock()) {
            if (temp->getParams().size() != params.size()) {
                cerr << "Function declaration has not the same number of arguments as Function definition " << endl;
                cerr << "Found : " << params.size() << endl;
                cerr << "Expected : " << temp->getParams().size() << endl;
                printDebugInfo(cerr, ctx);
                throw std::runtime_error("Different number of arguments");
            }
            int i=0;
            for (auto &&param : params) {
                if(param->getType() != temp->getParams().at(i)->getType()){
                    cerr << "Parameter "<< param->getName() <<" in function declaration has not the same type as in function definition" << endl;
                    cerr << "Found : " << param->getType() << endl;
                    cerr << "Expected : " << temp->getParams().at(i)->getType() << endl;
                    printDebugInfo(cerr, ctx);
                    throw std::runtime_error("Different type of arguments");
                }
                i++;
            }
            fDef = temp;
        }
    }

    currentSymbolTable->insert(name, new Symbol(currentSymbolTable, fDef, true));

    return nullptr;
}

antlrcpp::Any StartVisitor::visitTypeList(MapleGrammarParser::TypeListContext *ctx) {
    auto fParams = new vector<FunctionParam *>();

    for (std::size_t i = 0; i != ctx->ID().size(); i++) {
        const string &name = ctx->ID(i)->getText();

        if (auto symbol = currentSymbolTable->lookup(name)) {
            cerr << "Duplicate declaration of " << name << endl;
            cerr << "Found : " << symbol->getDeclaration() << endl;
            printDebugInfo(cerr, ctx);
            throw std::runtime_error("Duplicated declaration");
        }

        auto fParam = new FunctionParam(
                name,
                getTypeFromString(ctx->TYPE(i)->getText())
        );

        currentSymbolTable->insert(name, new Symbol(currentSymbolTable, fParam, true));
        fParams->push_back(fParam);
    }
    return fParams;
}

antlrcpp::Any StartVisitor::visitTypeListWithoutName(MapleGrammarParser::TypeListWithoutNameContext *ctx) {
    auto fParams = new vector<FunctionParam *>(ctx->ID().size());

    for (std::size_t i = 0; i != ctx->ID().size(); i++) {

        auto fParam = new FunctionParam(
                getTypeFromString(ctx->TYPE(i)->getText())
        );

        fParams->push_back(fParam);
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

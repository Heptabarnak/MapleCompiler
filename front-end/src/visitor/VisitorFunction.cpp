#include <iostream>
#include <Declarations.h>
#include <mapContext2Vector.h>
#include <typeHelper.h>

#include "StartVisitor.h"


using std::cerr;
using std::endl;

antlrcpp::Any StartVisitor::visitArgumentList(MapleGrammarParser::ArgumentListContext *ctx) {
    return mapContext2Vector<MapleGrammarParser::ExprContext *, Expr *>(ctx->expr(), this);
}


antlrcpp::Any StartVisitor::visitFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext *ctx) {
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        cerr << "Duplicate declaration of " << name << endl;
        cerr << "Found : " << symbol->getDeclaration() << endl;
        throw std::runtime_error("Duplicate definition");
    }

    FunctionDefinition *functionDefinition;

    Type type = Type::VOID;

    if (ctx->TYPE() != nullptr) {
        type = getTypeFromString(ctx->TYPE()->getText());
    }


    if (ctx->typeList() != nullptr) {
        functionDefinition = new FunctionDefinition(
                (BlockFunction *) visit(ctx->blockFunction()),
                type,
                visit(ctx->typeList()),
                name
        );
    } else {
        functionDefinition = new FunctionDefinition(
                (BlockFunction *) visit(ctx->blockFunction()),
                type,
                {},
                name
        );
    }

    currentSymbolTable->insert(name, new Symbol(currentSymbolTable, functionDefinition));

    return (Declaration *) functionDefinition;
}

antlrcpp::Any StartVisitor::visitTypeList(MapleGrammarParser::TypeListContext *ctx) {
    auto fParams = new vector<FunctionParam *>(ctx->ID().size());

    for (std::size_t i = 0; i != ctx->ID().size(); i++) {
        fParams->push_back(new FunctionParam(
                ctx->ID(i)->getText(),
                getTypeFromString(ctx->TYPE(i)->getText()))
        );
    }
    return fParams;
}

antlrcpp::Any StartVisitor::visitBlockFunction(MapleGrammarParser::BlockFunctionContext *ctx) {
    currentSymbolTable = new SymbolTable(currentSymbolTable);

    auto block = new BlockFunction(
            *mapContext2VectorFlat<MapleGrammarParser::DeclarationContext *, Declaration *>(ctx->declaration(), this),
            *mapContext2Vector<MapleGrammarParser::InstructionContext *, Instruction *>(ctx->instruction(), this),
            currentSymbolTable
    );

    currentSymbolTable = currentSymbolTable->getFather();
    return block;
}

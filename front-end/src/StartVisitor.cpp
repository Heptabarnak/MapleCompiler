#include <string>
#include <iostream>
#include <vector>
#include <vector>
#include <mapContext2Vector.h>
#include <typeHelper.h>

#include "Declarations.h"
#include "StartVisitor.h"

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

antlrcpp::Any StartVisitor::visitValue(MapleGrammarParser::ValueContext *ctx) {
    if (ctx->INTEGER() == nullptr) {
        return new ExprValue(new Value(Type::CHAR, ctx->CHAR()->getText().at(0)));
    }
    return new ExprValue(new Value(Type::INT64_T, stoi(ctx->INTEGER()->getText())));
}

antlrcpp::Any StartVisitor::visitStart(MapleGrammarParser::StartContext *ctx) {
    currentSymbolTable = new SymbolTable();

    // TODO Add putchar & getchar

    vector<Declaration *> declarations;

    for (auto &&item : ctx->program()) {
        auto dList = (vector<Declaration *>) visit(item);

        declarations.insert(declarations.end(), dList.begin(), dList.end());
    }

    return start = new Start(declarations, currentSymbolTable);
}

antlrcpp::Any StartVisitor::visitProgram(MapleGrammarParser::ProgramContext *ctx) {
    if (ctx->declaration()) {
        return visit(ctx->declaration());
    }
    return visit(ctx->functionDefinition());
}

antlrcpp::Any StartVisitor::visitExprValue(MapleGrammarParser::ExprValueContext *ctx) {
    return visit(ctx->value());
}

antlrcpp::Any StartVisitor::visitExprBinaryShift(MapleGrammarParser::ExprBinaryShiftContext *ctx) {
    return new ExprBinaryShiftOperation(
            (Expr *) (visit(ctx->expr(0))),
            (Expr *) (visit(ctx->expr(1))),
            ctx->opBinaryShift()->getText()
    );
}

antlrcpp::Any StartVisitor::visitExprAffectation(MapleGrammarParser::ExprAffectationContext *ctx) {
    return new ExprAffectation(
            visit(ctx->leftValue()),
            visit(ctx->expr()),
            ctx->opAffectation()->getText()
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryXor(MapleGrammarParser::ExprBinaryXorContext *ctx) {
    return new ExprBinaryXorOperation(
            (Expr *) (visit(ctx->expr(0))),
            (Expr *) (visit(ctx->expr(1)))
    );
}

antlrcpp::Any StartVisitor::visitExprBinaryAnd(MapleGrammarParser::ExprBinaryAndContext *ctx) {
    return new ExprBinaryAndOperation(
            (Expr *) visit(ctx->expr(0)),
            (Expr *) visit(ctx->expr(1))
    );
}

antlrcpp::Any StartVisitor::visitExprOr(MapleGrammarParser::ExprOrContext *ctx) {
    return new ExprOrOperation(
            (Expr *) (visit(ctx->expr(0))),
            (Expr *) (visit(ctx->expr(1)))
    );
}

antlrcpp::Any StartVisitor::visitExprUnaryPostfix(MapleGrammarParser::ExprUnaryPostfixContext *ctx) {
    return new ExprPostfixUnary(
            (Expr *) visit(ctx->expr()),
            ctx->opUnaryPostfix()->getText()
    );
}

antlrcpp::Any StartVisitor::visitExprMultiplicative(MapleGrammarParser::ExprMultiplicativeContext *ctx) {
    return new ExprMultiplicativeOperation(
            (Expr *) visit(ctx->expr(0)),
            (Expr *) visit(ctx->expr(1)),
            ctx->opMultiplicative()->getText()
    );
}

antlrcpp::Any StartVisitor::visitExprAdditive(MapleGrammarParser::ExprAdditiveContext *ctx) {
    return new ExprAdditiveOperation(
            (Expr *) visit(ctx->expr(0)),
            (Expr *) visit(ctx->expr(1)),
            ctx->opAdditive()->getText()
    );
}

antlrcpp::Any StartVisitor::visitExprAccessor(MapleGrammarParser::ExprAccessorContext *ctx) {
    return new ExprAccessor((Accessor *) visit(ctx->accessor()));
}

antlrcpp::Any StartVisitor::visitExprAnd(MapleGrammarParser::ExprAndContext *ctx) {
    return new ExprAndOperation(
            (Expr *) (visit(ctx->expr(0))),
            (Expr *) (visit(ctx->expr(1)))
    );
}

antlrcpp::Any StartVisitor::visitExprParenthesis(MapleGrammarParser::ExprParenthesisContext *ctx) {
    return new ExprParenthesis((Expr *) (visit(ctx->expr())));
}

antlrcpp::Any StartVisitor::visitExprBinaryOr(MapleGrammarParser::ExprBinaryOrContext *ctx) {
    return new ExprBinaryOrOperation(
            (Expr *) visit(ctx->expr(0)),
            (Expr *) visit(ctx->expr(1))
    );
}

antlrcpp::Any StartVisitor::visitExprCompareRelational(MapleGrammarParser::ExprCompareRelationalContext *ctx) {
    return new ExprRelationalComparisonOperation(
            (Expr *) (visit(ctx->expr(0))),
            (Expr *) (visit(ctx->expr(1))),
            ctx->opCompareRelational()->getText()
    );
}

antlrcpp::Any StartVisitor::visitExprCompareEquality(MapleGrammarParser::ExprCompareEqualityContext *ctx) {
    return new ExprEqualityComparisonOperation(
            (Expr *) (visit(ctx->expr(0))),
            (Expr *) (visit(ctx->expr(1))),
            ctx->opCompareEquality()->getText()
    );
}

antlrcpp::Any StartVisitor::visitExprUnaryPrefix(MapleGrammarParser::ExprUnaryPrefixContext *ctx) {
    return new ExprPrefixUnary(
            (Expr *) visit(ctx->expr()),
            ctx->opUnaryPrefix()->getText()
    );
}

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

antlrcpp::Any StartVisitor::visitAssignment(MapleGrammarParser::AssignmentContext *ctx) {
    return (Expr *) visit(ctx->expr());
}

antlrcpp::Any StartVisitor::visitAccessorTab(MapleGrammarParser::AccessorTabContext *ctx) {
    // We should note that we could allow access to a variable as an array is technically a variable !
    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        if (auto symbolTab = dynamic_cast<TabDeclaration *>(symbol)) {

            return new TabAccessor(
                    symbolTab,
                    (Expr *) visit(ctx->expr())
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
        if (auto symbolVar = dynamic_cast<VarDeclaration *>(symbol)) {

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
        if (auto symbolFun = dynamic_cast<FunctionDefinition *>(symbol)) {

            return new AccessorFunction(
                    symbolFun,
                    (vector<Expr *>) visit(ctx->argumentList())
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

antlrcpp::Any StartVisitor::visitAccessor(MapleGrammarParser::AccessorContext *ctx) {
    if (ctx->accessorFunction() == nullptr) {
        return new LeftValueAccessor((LeftValue *) (visit(ctx->leftValue())));
    }
    return new FunctionAccessor((AccessorFunction *) (visit(ctx->accessorFunction())));
}

antlrcpp::Any StartVisitor::visitIfStatement(MapleGrammarParser::IfStatementContext *ctx) {
    return new IfStatement(
            (Expr *) visit(ctx->expr()),
            (Statement *) visit(ctx->instruction()),
            (Instruction *) visit(ctx->elseStatement())
    );
}

antlrcpp::Any StartVisitor::visitElseStatement(MapleGrammarParser::ElseStatementContext *ctx) {
    return visit(ctx->instruction());
}

antlrcpp::Any StartVisitor::visitWhileStatement(MapleGrammarParser::WhileStatementContext *ctx) {
    return new WhileStatement(
            (Expr *) (visit(ctx->expr())),
            (Instruction *) (visit(ctx->instruction()))
    );
}

antlrcpp::Any StartVisitor::visitReturnStatement(MapleGrammarParser::ReturnStatementContext *ctx) {
    return new ReturnStatement((Expr *) (visit(ctx->expr())));
}

antlrcpp::Any StartVisitor::visitArgumentList(MapleGrammarParser::ArgumentListContext *ctx) {
    return mapContext2Vector<MapleGrammarParser::ExprContext *, Expr *>(ctx->expr(), this);
}

antlrcpp::Any StartVisitor::visitBlock(MapleGrammarParser::BlockContext *ctx) {
    return new Block(
            mapContext2Vector<MapleGrammarParser::InstructionContext *, Instruction *>(ctx->instruction(), this)
    );
}

antlrcpp::Any StartVisitor::visitStatement(MapleGrammarParser::StatementContext *ctx) {
    return new Statement((Expr *) (visit(ctx->expr())));
}

antlrcpp::Any StartVisitor::visitInstruction(MapleGrammarParser::InstructionContext *ctx) {
    if (ctx->statement() != nullptr) {
        return visit(ctx->statement());
    }
    if (ctx->ifStatement() != nullptr) {
        return visit(ctx->ifStatement());
    }
    if (ctx->whileStatement() != nullptr) {
        return visit(ctx->whileStatement());
    }
    if (ctx->block() != nullptr) {
        return visit(ctx->block());
    }
    return visit(ctx->returnStatement());
}

antlrcpp::Any StartVisitor::visitFunctionDefinition(MapleGrammarParser::FunctionDefinitionContext *ctx) {
    vector<FunctionParam *> fParams;

    if (ctx->typeList() != nullptr) {
        fParams = (vector<FunctionParam *>) visit(ctx->typeList());
    }

    const string &name = ctx->ID()->getText();

    if (auto symbol = currentSymbolTable->lookup(name)) {
        // TODO Throw error, duplicate definition
        cerr << "Duplicate declaration of " << name << endl;
        cerr << "Found : " << symbol->getDeclaration() << endl;
        return nullptr;
    }

    FunctionDefinition *functionDefinition = new FunctionDefinition(
            (BlockFunction *) visit(ctx->blockFunction()),
            getTypeFromString(ctx->TYPE()->getText()),
            fParams,
            name
    );

    currentSymbolTable->insert(name, new Symbol(currentSymbolTable, functionDefinition));

    return functionDefinition;
}

antlrcpp::Any StartVisitor::visitTypeList(MapleGrammarParser::TypeListContext *ctx) {
    vector<FunctionParam *> fParams;
    for (std::size_t i = 0; i != ctx->ID().size(); i++) {
        fParams.push_back(new FunctionParam(
                ctx->ID(i)->getText(),
                getTypeFromString(ctx->TYPE(i)->getText()))
        );
    }
    return fParams;
}

antlrcpp::Any StartVisitor::visitBlockFunction(MapleGrammarParser::BlockFunctionContext *ctx) {
    currentSymbolTable = new SymbolTable(currentSymbolTable);

    auto block = new BlockFunction(
            mapContext2Vector<MapleGrammarParser::DeclarationContext *, Declaration *>(ctx->declaration(), this),
            mapContext2Vector<MapleGrammarParser::InstructionContext *, Instruction *>(ctx->instruction(), this),
            currentSymbolTable
    );

    currentSymbolTable = currentSymbolTable->getFather();
    return block;
}


antlrcpp::Any
StartVisitor::visitDeclarationVarDefinition(MapleGrammarParser::DeclarationVarDefinitionContext *context) {
    return antlrcpp::Any();
}

antlrcpp::Any StartVisitor::visitDeclarationVar(MapleGrammarParser::DeclarationVarContext *ctx) {
    /*vector<VarDeclaration*> declarationList;
    if(ctx->assignment().empty()){
        for(std::size_t i = 0; i != ctx->ID().size(); i++) {
            declarationList.push_back(new VarDeclaration(ctx->ID(i)->getText(),  getTypeFromString(ctx->TYPE()->getText()), nullptr));
        }
    } else {
        for(std::size_t i = 0; i != ctx->ID().size(); i++) {
            //à modifier surement plus tard
            if()declarationList.push_back(new VarDeclaration(ctx->ID(i)->getText(),  getTypeFromString(ctx->TYPE()->getText()),(Expr*)visit((ctx->assignment(i))));
        }
    }
    return declarationList;*/
}
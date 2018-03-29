#include <iostream>
#include <targets/X86_64.h>
#include <tree-walk/MapleTreeWalk.h>
#include <visitor/StartVisitor.h>
#include <maple-parser/MapleGrammarLexer.h>
#include <cstring>
#include "Runner.h"

using antlr4::ANTLRInputStream;
using antlr4::CommonTokenStream
using antlr4::tree::ParseTree;
using std::cerr;
using std::cout;
using std::endl;

int Runner::run(Config *conf) {

    std::fstream inputFile;
    inputFile.open(conf->fileToCompile, std::fstream::in);

    std::cout << "Opening file: " << conf->fileToCompile << std::endl;

    if (!inputFile) {
        std::cerr << "Error opening input file: " << strerror(errno);
        return 1;
    }


    // Parsing

    ANTLRInputStream input(inputFile);
    MapleGrammarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MapleGrammarParser parser(&tokens);

    ParseTree *tree = parser.start();

    if (parser.getNumberOfSyntaxErrors() != 0) {
        std::cerr << "Error while parsing" << std::endl;
        return 1;
    }

    // AST Generation

    StartVisitor visitor(conf);
    Start *ast;

    try {
        ast = visitor.visit(tree);
        std::cout << "AST Generated !" << std::endl;
        if (conf->staticAnalysis) {
            ast->getGlobalSymbolTable()->staticAnalysis();
        }
    } catch (std::exception &exception) {
        std::cerr << "Error while creating AST :" << std::endl << exception.what();
        return 1;
    }


    // TreeWalk

    std::map<std::string, CFG *> cfgs;

    try {
        MapleTreeWalk treeWalk(ast);
        cfgs = treeWalk.generateIR();
    } catch (std::exception &exception) {
        std::cerr << "Error in TreeWalk :" << std::endl << exception.what();
        return 1;
    }


    // ASM Generation

    if (conf->generateAsm) {
        try {
            BaseTarget target = nullptr;
            switch (conf->target) {
                case X86_64:
                    target = X86_64::X86_64(conf, cfgs);
                    break;
                case JAVA:
                case MSP430:
                    std::cerr << "This target is not available for now. Sorry for the inconvenience" << std::endl;
                    return 1;
            }

            target.parse();

            if (conf->linkAsm) {
                target.compile();
            }
        } catch (std::exception &exception) {
            std::cerr << "Error in IR Generation :" << std::endl << exception.what();
            return 1;
        }
    }

    return 0;
}

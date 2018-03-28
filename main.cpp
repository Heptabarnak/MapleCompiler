#include <iostream>
#include <antlr4-runtime.h>
#include <maple-parser/MapleGrammarParser.h>
#include <maple-parser/MapleGrammarLexer.h>
#include <visitor/StartVisitor.h>
#include <cstring>
#include <exception>
#include <typeinfo>
#include <stdexcept>
#include <tree-walk/MapleTreeWalk.h>
#include <targets/X86_64.h>


using namespace antlr4;

using std::cerr;
using std::cout;
using std::endl;

int main(int argc, const char **argv) {

    if (argc != 2) {
        std::cerr << "Not enough arguments" << std::endl;
        return 1;
    }

    std::fstream inputFile;
    inputFile.open(argv[1], std::fstream::in);

    std::cout << "Opening file: " << argv[1] << std::endl;

    if (!inputFile) {
        std::cerr << "Error opening input file: " << strerror(errno);
        return 1;
    }


    // Parsing

    ANTLRInputStream input(inputFile);
    MapleGrammarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MapleGrammarParser parser(&tokens);

    tree::ParseTree *tree = parser.start();

    if (parser.getNumberOfSyntaxErrors() != 0) {
        cerr << "Error while parsing" << endl;
        return 1;
    }


    // AST Generation

    StartVisitor visitor;
    Start *ast;

    try {
        ast = visitor.visit(tree);
        cout << "AST Generated !" << endl;
        ast->getGlobalSymbolTable()->staticAnalysis();
    } catch (std::exception &exception) {
        cerr << "Error while creating AST :" << endl << exception.what();
        return 1;
    }


    // TreeWalk

    std::map<std::string, CFG *> cfgs;

    try {
        MapleTreeWalk treeWalk(ast);
        cfgs = treeWalk.generateIR();
    } catch (std::exception &exception) {
        cerr << "Error in TreeWalk :" << endl << exception.what();
        return 1;
    }


    // ASM Generation

    try {
        X86_64 target(argv[1], cfgs);

        target.parse();

        // TODO Option
        target.compile();
    } catch (std::exception &exception) {
        cerr << "Error in IR Generation :" << endl << exception.what();
        return 1;
    }

    return 0;
}
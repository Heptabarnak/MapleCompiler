#include <iostream>
#include <antlr4-runtime.h>
#include <maple-parser/MapleGrammarParser.h>
#include <maple-parser/MapleGrammarLexer.h>
#include <visitor/StartVisitor.h>
#include <cstring>
#include <exception>
#include <typeinfo>
#include <stdexcept>


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


    ANTLRInputStream input(inputFile);
    MapleGrammarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MapleGrammarParser parser(&tokens);

    tree::ParseTree *tree = parser.start();
    StartVisitor visitor;

    Start * ast;

    try {
        ast = visitor.visit(tree);
        cout << "AST Generated !" << endl;
        ast->getGlobalSymbolTable()->staticAnalysis();
    } catch (std::exception &exception) {
        cerr << "Error while creating AST :" << endl << exception.what();
    }

    // TODO Send AST to back-end (it already contains a symbol table)

    return 0;
}
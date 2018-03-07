#include <iostream>
#include <antlr4-runtime.h>
#include "maple-parser/MapleGrammarParser.h"
#include "maple-parser/MapleGrammarLexer.h"
#include "maple-parser/MapleGrammarBaseVisitor.h"


using namespace antlr4;

int main(int argc, const char **argv) {

    if (argc != 2) {
        std::cerr << "Not enough arguments" << std::endl;
        return 1;
    }

    std::fstream inputFile;
    inputFile.open(argv[1], std::fstream::in);

    if (!inputFile) {
        std::cerr << "Error opening input file";
        return 1;
    }


    ANTLRInputStream input(inputFile);
    MapleGrammarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();
    for (auto token : tokens.getTokens()) {
        std::cout << token->toString() << std::endl;
    }

    MapleGrammarParser parser(&tokens);
    tree::ParseTree *context = parser.start();

    return 0;
}
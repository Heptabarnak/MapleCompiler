#include <iostream>
#include <antlr4-runtime.h>
#include <maple-parser/MapleGrammarParser.h>
#include <maple-parser/MapleGrammarLexer.h>
#include <maple-parser/MapleGrammarBaseVisitor.h>
#include <StartVisitor.h>


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
    MapleGrammarParser parser(&tokens);

    /*
    tree::ParseTree *tree = parser.start();

    StartVisitor visitor;

    auto e = visitor.visit(tree);
*/

    tree::ParseTree *tree = parser.value();

    return 0;
}
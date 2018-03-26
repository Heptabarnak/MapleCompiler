#include "printDebugInfo.h"

void printDebugInfo(std::ostream &o, antlr4::ParserRuleContext *ctx) {
    auto start = ctx->getStart();

    o << "At line: " << start->getLine() << ", column: " << start->getCharPositionInLine() << std::endl;
}
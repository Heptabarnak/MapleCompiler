#ifndef MAPLECOMPILER_PRINTDEBUGINFO_H
#define MAPLECOMPILER_PRINTDEBUGINFO_H

#include <ostream>
#include <antlr4-runtime.h>

void printDebugInfo(std::ostream &o, antlr4::ParserRuleContext *ctx) {
    auto start = ctx->getStart();

    o << "At line: " << start->getLine() << ", column: " << start->getCharPositionInLine() << std::endl;
}

#endif //MAPLECOMPILER_PRINTDEBUGINFO_H

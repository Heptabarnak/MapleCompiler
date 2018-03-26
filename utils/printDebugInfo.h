#ifndef MAPLECOMPILER_PRINTDEBUGINFO_H
#define MAPLECOMPILER_PRINTDEBUGINFO_H

#include <ostream>
#include <antlr4-runtime.h>

void printDebugInfo(std::ostream &o, antlr4::ParserRuleContext *ctx);

#endif //MAPLECOMPILER_PRINTDEBUGINFO_H

#include <str2int.h>
#include <ostream>
#include <ir/instructions/UnaryOpInstr.h>
#include "ExprPrefixUnary.h"

using namespace std;

ExprPrefixUnary::ExprPrefixUnary(Expr *expr, const string &op) : ExprUnary(expr) {

    switch (str2int(op.c_str())) {
        case str2int("+"):
            prefixOp = PLUS;
            break;
        case str2int("-"):
            prefixOp = MINUS;
            break;
        case str2int("!"):
            prefixOp = NOT;
            break;
        case str2int("~"):
            prefixOp = BITWISE_NOT;
            break;
        default:
            cerr << "Operator expected to be \"+\", \"-\", \"!\" or \"~\" but did not match." << endl;
            break;
    }
}

bool ExprPrefixUnary::isSimplifiable() {
    return expr->isSimplifiable();
}

long ExprPrefixUnary::simplify() {
    switch (prefixOp) {
        case PLUS:
            return +expr->simplify();
        case MINUS:
            return -expr->simplify();
        case NOT:
            return !expr->simplify();
        case BITWISE_NOT:
            return ~expr->simplify();
    }
}

string ExprPrefixUnary::buildIR(CFG *cfg) {
    string var1 = expr->buildIR(cfg);
    string var = cfg->createNewTmpVar(Type::INT64_T);

    UnaryOpInstr::UnaryOpType opType = UnaryOpInstr::PLUS;
    switch (prefixOp) {
        case PLUS:
            opType = UnaryOpInstr::PLUS;
            break;
        case MINUS:
            opType = UnaryOpInstr::MINUS;
            break;
        case NOT:
            opType = UnaryOpInstr::NOT;
            break;
        case BITWISE_NOT:
            opType = UnaryOpInstr::BITWISE_NOT;
            break;
    }

    auto instr = new UnaryOpInstr(cfg->currentBB, opType, var, var1);
    cfg->addIRInstr(instr);

    return var;
}

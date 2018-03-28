#include "X86_64.h"

X86_64::X86_64(const string &filename, map<string, CFG *> &cfgs) : BaseTarget(filename, cfgs) {}

void X86_64::parse() {
    for (auto &&cfg : cfgs) {
        currentCFG = cfg.second;

        prologue();

        parseBasicBlocks();

        epilogue();
    }
}

void X86_64::compile() {

}

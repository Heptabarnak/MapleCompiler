#include "BaseTarget.h"

using std::string;
using std::map;
using std::ofstream;

BaseTarget::BaseTarget(Config *config, map<string, CFG *> &cfgs)
        : conf(config), cfgs(cfgs) {
    output = new ofstream();
}

void BaseTarget::open() {
    output->open(conf->fileToCompile + ".s", std::ios_base::trunc);

    if (!output->is_open()) {
        // TODO Throw error
    }
}

void BaseTarget::close() {
    if (output->is_open()) {
        output->close();
    }
}

void BaseTarget::write(const string line) {
    // If not open, try to open it

    if (!output->is_open()) {
        // TODO Throw error
        return;
    }
    (*output) << line.c_str() << '\n';

}

bool BaseTarget::isOpen() {
    return output->is_open();
}

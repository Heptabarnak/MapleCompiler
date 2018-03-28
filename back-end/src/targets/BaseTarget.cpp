#include "BaseTarget.h"

BaseTarget::BaseTarget(const std::string filename, std::map<std::string, CFG *> &cfgs)
        : filename(filename), cfgs(cfgs) {
    output = new std::ofstream();
}

void BaseTarget::open() {
    output->open(filename + ".s", std::ios_base::trunc);

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

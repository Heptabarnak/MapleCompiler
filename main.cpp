#include <Runner.h>
#include <parseConfig.h>


int main(int argc, char *const *argv) {

    Config* conf = parseConfig(argc, argv);

    if (conf == nullptr) {
        return 1;
    }
    Runner runner;

    return runner.run(conf);
}

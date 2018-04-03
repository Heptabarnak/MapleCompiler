#include<inttypes.h>

int64_t get2() {
    return 2;
}

void main() {
    int64_t x = 0;

    putchar('0' + get2());

    putchar('\n');
}

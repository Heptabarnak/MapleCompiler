#include<inttypes.h>


void main() {
    int64_t i = 5;
    int64_t j = 2;

    putchar('0' + (i << j));
    putchar('0' + (i >> j));

    putchar('\n');
}
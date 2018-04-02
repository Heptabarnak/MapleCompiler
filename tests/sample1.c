#include<inttypes.h>

void main() {
    int64_t x = 0;

    while (x < 26) {
        putchar('A' + x);
        x++;
    }

    putchar('\n');
}

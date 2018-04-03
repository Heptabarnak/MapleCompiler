#include<inttypes.h>

void b(char);

void a() {
    b();
}

void b(char c) {
    a();
}

void main() {
    int64_t x = 0;

    a();
    putchar('0' + x);

    putchar('\n');
}

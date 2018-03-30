#include<inttypes.h>

void call(char b, char c, char d, char e, char f, char g, char h, char i, char j) {
    putchar(b);
    putchar(c);
    putchar(d);
    putchar(e);
    putchar(f);
    putchar(g);
    putchar(h);
    putchar(i);
    putchar(j);
    putchar('\n');
}

void main() {
    int64_t x = 1;
    int64_t y = 2;
    int64_t z = 3;
    call('t', 'e', 's', 't', ' ', 'h', 'e', 'l', 'l');
}

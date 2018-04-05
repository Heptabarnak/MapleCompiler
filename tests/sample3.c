#include<inttypes.h>


void main() {
    int64_t i = 5;
    int64_t j = 2;

//    putchar('0' + (i << j));
//    putchar('0' + (i >> j));
    char a[10];

    for (i = 0; i < 10; i++) {
        a[i] = getchar();
    }
    putchar('\n');

    for (i = 0; i < 10; i++) {
        putchar(a[i]);
    }

    putchar('\n');
}
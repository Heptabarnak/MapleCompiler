void main(){
    int64_t i = 5;

    putchar('i');
    putchar('=');
    putchar('0' + i);
    putchar('\n');
    putchar('\n');

    putchar('0' + i++);
    putchar('\n');
    putchar('0' + i);
    putchar('\n');
    putchar('\n');

    putchar('0' + i--);
    putchar('\n');
    putchar('0' + i);
    putchar('\n');
    putchar('\n');
    putchar('\n');

    putchar('0' + ++i);
    putchar('\n');
    putchar('0' + i);
    putchar('\n');
    putchar('\n');
    putchar('\n');

    putchar('0' + --i);
    putchar('\n');
    putchar('0' + i);
    putchar('\n');
    putchar('\n');
    putchar('\n');

}
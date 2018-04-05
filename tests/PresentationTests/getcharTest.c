void main(){
    char word[100];
    int64_t i = 0;


    while (word[i-1] != '\n') {
        word[i] = getchar();
        i++;
    }

    putchar('S');
    putchar('a');
    putchar('i');
    putchar('d');
    putchar(':');
    putchar(' ');
    i = 0;

    while(word[i] != '\n'){
        putchar(word[i]);
        i++;
    }
    putchar('\n');
}
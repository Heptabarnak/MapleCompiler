//char globVar[] = "Hello test";

void main(){
    int64_t i = 0;
    char globVar[] = "Hello test";

    while(globVar[i] != '\0'){
        putchar(globVar[i]);
        i++;
    }

    putchar('\n');
}
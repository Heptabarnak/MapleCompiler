int64_t function1(int64_t);
int64_t function2(int64_t);

int64_t function1(int64_t a)
{
    function2(a);
    putchar('0' + a);
    a++;
    putchar('\n');
}

int64_t function2(int64_t b)
{
    if (b > 5)
    {
        function1(b);
    } else{
        return b;
    }
}

void main(){
    int64_t i = 0;

    printChar(i);
}
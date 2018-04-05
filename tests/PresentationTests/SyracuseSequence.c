void main(){
    int64_t u0 = 1;
    int64_t sequence[8];
    int64_t i;
    sequence[0] = u0;

    for (i=0; i < 8; i++)
    {

        if (sequence[i]%2 == 0)
        {
            sequence[i+1] = sequence[i]/2;

        }
        else
        {
            sequence[i+1] = 3*sequence[i];
        }
    }

    for (i = 0; i < 8; i++){
        putchar('0' + sequence[i]);
        putchar('\n');
    }

}
void main(){
    int64_t u0 = 14;
    int64_t sequence[20];
    int64_t sequenceSize = 20;
    int64_t i;
    int64_t j = 0;
    int64_t digit;
    int64_t digits[20];
    sequence[0] = u0;

    for (i=0; i < sequenceSize; i++)
    {

        if (sequence[i]%2 == 0)
        {
            sequence[i+1] = sequence[i]/2;

        }
        else
        {
            sequence[i+1] = 3*sequence[i] + 1;
        }
    }


    for (i = 0; i < sequenceSize; i++){
        j = 0;
        while (sequence[i] > 0) {
            digit = sequence[i] % 10;
            digits[j] = digit;
            sequence[i] /= 10;
            j++;
        }
        j--;
        while (j >= 0) {
            putchar('0' + digits[j]);
            j--;
        }
        putchar('\n');
    }

}
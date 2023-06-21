#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned int y);

int main()
{
    unsigned int y = 136; // y = 1000 1000
    int n = 5;
    int p = 6;
    unsigned int x = setbits(x, p, n, y); // Expected x = 1111 1100 (= 252);
    printf("%d\n", x);
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned int y)
{
    unsigned _BIT_MASKING = (~(~0 << n)) << (p - n +1);
    
    return x =  y | _BIT_MASKING;
}

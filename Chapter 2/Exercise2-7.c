#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main()
{
    unsigned x = 238; // x = 1110 1110
    int p = 4;
    int n = 4;
    x = invert(x, p, n); // Expected x = 1111 0000 = 240 (10)
    printf("%d\n", x);
    return 0;
}

/* invert: return x with the n bits begin at p inverted, other bits are unchange */
unsigned int invert(unsigned int x, int p, int n)
{
    unsigned int _BIT_MASKING = ~(~0 << p) << (p - n + 1);
    return x = x ^ _BIT_MASKING;
}
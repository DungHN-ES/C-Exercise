#include "stdio.h"

unsigned int rightrot(unsigned int x, int n);
unsigned int binaryLen(unsigned int x);

/* test function rightrot */
int main()
{
    unsigned int x = 239; // x = 1110 1111
    int n = 3;
    x = rightrot(x, 3); // Expected: x = 1111 1101 = 253 (in base 10)
    printf("%d\n", x);
    return 0;
}

/* rightrot: return value of x rotated to the right by n bit positions */
unsigned int rightrot(unsigned int x, int n)
{
    unsigned int rotatedBits = x & (~(~0 << n));
    unsigned int xLen = binaryLen(x);

    x = x >> n;
    rotatedBits = rotatedBits << (xLen - n);
    return x = x | rotatedBits;

}

/* binaryLen: return the length of int x in binary form */
unsigned int binaryLen(unsigned int x)
{
    unsigned int len = 0;

    if (x == 0) return 0;
    

    while (x / 2)
    {
        ++len;
        x = x >> 1;
    }
    return len+1;
}
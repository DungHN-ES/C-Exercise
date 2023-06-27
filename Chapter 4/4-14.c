#include <stdio.h>

#define swap(x,y,t) t z; z = x; x = y; y = z;

int main()
{
    int x = 3, y = 5;
    printf("Before: x = %d  &  y = %d \n\n", x, y);
    swap(x,y,int);
    printf("After: x = %d  &  y = %d\n\n", x, y);
    return 0;
}
#include <stdio.h>

int lower(int c);

/* Test */
int main()
{
    int c = 'B';
    c = lower(c);
    printf("%c\n", c);
    return 0;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    (c >= 'A' && c <= 'Z') ? c = c + 'a' - 'A' : c;
    return c;
}
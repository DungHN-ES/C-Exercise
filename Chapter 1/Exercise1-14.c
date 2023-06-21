#include <stdio.h>

#define TOTAL_CHAR 128

/*
 Print the frequencies of different characters in its input
*/

int main()
{
    int nDigit[TOTAL_CHAR];
    int c;

    for (int i = 0; i < TOTAL_CHAR; ++i)
        nDigit[i] = 0;
    
    while ((c = getchar()) != EOF)
    {
        ++nDigit[c];
    }

    for (int i = 0; i < TOTAL_CHAR; ++i)
    {   
        putchar(i);
        for (int j = 1; j < nDigit[i]; ++j)
            putchar('*');
        putchar('\n');
    }
    return 0;
}
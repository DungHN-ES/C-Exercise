#include "stdio.h"

#define IN 1
#define OUT 0

int main()
{
    int c, linesCounter, wordsCounter, charsCounter, state;
    linesCounter = 1;
    wordsCounter = charsCounter = 0;
    state = OUT;
    while ((c = getchar()) != EOF)
    {
        ++charsCounter;

        if (c == '\n')
        ++linesCounter;
        else if (c == ' '||c == '\n'||c == '\t')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++wordsCounter;
        }
    }
    printf("%d lines - %d words - %d characters.", linesCounter, wordsCounter, charsCounter);
    return 0;
}

/*
Blanks are most likely to uncover bugs.
*/
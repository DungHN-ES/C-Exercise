#include "stdio.h"

int main()
{
    int c, lineCount, blankCount, tabCount;

    lineCount = 1;
    blankCount = 0;
    tabCount = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            lineCount++;
        else if (c == '\t')
            tabCount++;
        else if (c == ' ')
            blankCount++;
    }
    printf("Number of line: %d\nNumber of tab: %d\nNumber of blank: %d\n", lineCount, tabCount, blankCount);
    return 0;
}
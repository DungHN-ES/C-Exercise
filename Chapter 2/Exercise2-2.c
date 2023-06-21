#include <stdio.h>

/* getline: read a line into s, return the length of line */
// int getLine(char line[], int maxLength)
// {
//     int c, lineSize;
//     lineSize = 0;

//     for (int i = 0; i < maxLength - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
//     {
//         line[i] = c;
//         lineSize++;
//     }
//     if (c == '\n')
//     {
//         line[lineSize] = '\0';
//     }
//     return lineSize ;
// }

/* Rewrite getLine() without using && or || */
int getLine(char lineIn[], int maxLen)
{
    int c;
    int i;

    for (i = 0; i < maxLen; ++i)
    {
        c = getchar();
        if (c == EOF)
            break;
        else if (c == '\n')
            break;
        else
            lineIn[i] = c;
    }
    if (c == '\n')
    {
        lineIn[i] = c;
        lineIn[i+1]  = '\0';
    }
    return i+1;
}

int main()
{
    return 0;
}
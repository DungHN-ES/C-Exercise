#include <stdio.h>
#define MAX_LEN 1000 // Maximum input line length

int getLine(char linee[], int Length);
void copy(char to[], char from[]);

/* Print the longest line from input */
int main() {
    char line[MAX_LEN];
    char longestLine[MAX_LEN];
    int lineSize;
    
    int longestLineSize = 0;

    while ((lineSize = getLine(line, MAX_LEN)) > 0)
    {
        if (lineSize > longestLineSize)
        {
            longestLineSize = lineSize;
            copy(longestLine, line);
        }
    }

    printf("The longest size is %d digit\nContext: ", longestLineSize);

    if (longestLineSize > 0)
        printf("%s", longestLine);
    return 0;
}

/* getline: read a line into s, return the length of line */
int getLine(char line[], int maxLength)
{
    int c, lineSize;
    lineSize = 0;

    for (int i = 0; i < maxLength - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
        lineSize++;
    }
    if (c == '\n')
    {
        line[lineSize] = '\0';
    }
    return lineSize ;
}
/* copy: copy "from" into "to": assume "to" size is enough */
void copy (char to[], char from[])
{
    int i = 0;
    
    while ((to[i] = from[i]) != '\0')
        ++i;
}
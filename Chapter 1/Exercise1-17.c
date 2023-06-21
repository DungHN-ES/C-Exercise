#include <stdio.h>

#define MAX_LEN 1000 // Maximum length of an input line
#define LIMIT 3

int getLine(char line[]);
void copy(char from[], char to[]);

/* Print all the input line that have the length longer than LIMIT */
int main()
{  
    int lineLen = 0;
    char lineIn[MAX_LEN];
    

    while ((lineLen = getLine(lineIn)) > 0)
    {
        if (lineLen > LIMIT)
        {
            printf("%s\n", lineIn);
        }
    }

    return 0;
}
/* getLine: read a input line into lineIn, return the length of line */
int getLine(char lineIn[])
{
    int length = 0;
    char c;
    for (int i = 0; i < MAX_LEN && (c = getchar()) != EOF && c != '\n'; ++i)    {
        lineIn[i] = c;
        length++;
    }
    lineIn[length] = '\0';
    return length;
}
/* copy: copy "from" into "to" assume the target array is big enough */
void copy(char from[], char to[])
{
    int i = 0;

    while ((to[i] = from[i]) != EOF)
        ++i;
}
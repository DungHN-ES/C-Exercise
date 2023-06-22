#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int getLine(char s[], int maxLen);
void escape(char to[], char from[]);

int main()
{
    char s[MAX_LEN], t[MAX_LEN];
    getLine(t, MAX_LEN);
    escape(s, t);
    printf("%s\n", s);
    return 0;
}

int getLine(char s[], int maxLen)
{
    int c,i;
    
    for (i = 0; i < maxLen - 1 && (c = getchar()) != EOF ; ++i)
        s[i] = c;
    s[++i] = '\0';
    return i;
}

void escape(char to[], char from[])
{
    int j = 0;
    for (int i = 0; from[i] != '\0'; ++i)
    {
        switch (from[i])
        {
        case '\n':
            to[j++] = '\\';
            to[j++] = 'n';
            break;
        case '\t':
            to[j++] = '\\';
            to[j++] = 't';
            break;
        default:
            to[j++] = from[i];
            break;
        }
    }
    to[j] = '\0';
}
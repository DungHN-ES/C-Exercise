#include <stdio.h>

int strrindex(char s[], int t);

int main()
{
    char s[] = "abcdefgh";
    printf("%d\n",strrindex(s, 'h'));
    return 0;
}

int strrindex(char s[], int t)
{
    int result = -1;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == t)  result = i;
    }
    return result;
}
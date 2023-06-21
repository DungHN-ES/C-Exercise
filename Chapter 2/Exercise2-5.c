#include "stdio.h"

int any(char s1[], char s2[]);

int main()
{
    char s1[] = "abcdefgh";
    char s2[] = "hello";
    printf("%d\n", any(s1,s2));
    return 0;
}

int any(char s1[], char s2[])
{
    int j;

    for (int i = 0; s1[i] != '\0'; ++i)
    {
        for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++);

        if (s2[j] != '\0')
            return i;
    }

    return -1;
}
#include "stdio.h"

void squeeze(char s[], int c);
void squeeze_m(char s1[], char s2[]);
void squeeze_M(char s1[], char s2[]);

int main()  
{
    char s[] = "abcdfega";
    char s1[] = "aceg";
    squeeze_M(s, s1);
    printf("%s\n", s);
    return 0;
}

/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
    int i, j;

    for (int i = j = 0; s[i] != '\0'; ++i)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* squeeze_m: deletes each character in s1 that matches any character in s2 */
void squeeze_m(char s1[], char s2[])
{
    for (int i = 0; s2[i] != '\0'; ++i)
    {
        squeeze(s1, s2[i]);
    }
}

// Another version of squeeze_m
void squeeze_M(char s1[], char s2[])
{
    int k = 0;
    int j;

    for (int i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s1[i] != s2[j] && s2[j] != '\0'; j++);
        if (s2[j] == '\0')
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}

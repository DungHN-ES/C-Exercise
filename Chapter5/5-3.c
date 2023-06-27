#include <stdio.h>
#include <string.h>

int strend(char *s, char* t);
int isEqual(char *, char *);

int main()
{   
    char *s = "Nghia Dung";
    char *pattern = "ung";
    printf("%d\n", strend(s, pattern));
    return 0;
}

int strend(char *s, char *t)
{
    int result = -1;
    while (*s != '\0') {
        if (isEqual(s,t))
            return 1;
        s++;
    }
    return -1;
}

int isEqual(char *s1, char *s2)
{
    return (strcmp(s1, s2)) ? 0 : 1;
}
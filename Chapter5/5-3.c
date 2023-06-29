#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strCat(char *s, char *t);

int main()
{
    char *s = "Hoang ";
    char *t = "Dung";
    char *new = NULL;
    new = strCat(s, t);
    printf("%s\n", new);
    return 0;
}

char *strCat(char *s, char *t)
{
    char *tmp = (char*)malloc((strlen(s) + strlen(t) + 1) * sizeof(char));
    int i, j;
    for (i = 0; i < strlen(s); ++i)
    {
        *(tmp+i) = *(s+i);
    }
    for (j = 0; j < strlen(t); j++, i++)
    {
        *(tmp+i) = *(t+j);
    }
    *(tmp+i) = '\0';
    return tmp;
}
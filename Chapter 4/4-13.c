#include  <stdio.h>
#include <string.h>

void reverse(char str[]);

int main()
{
    char str[] = "Nghia Dung";
    printf("%s\n", str);
    reverse(str);
    printf("%s\n", str);
    return 0;
}

void reverse(char s[])
{
    static int i;
    static int len;

    if (i == 0)
        len = strlen(s);
    
    int j = len - i - 1;

    if (i < j)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        ++i;
        reverse(s);
    }
    else 
    {
        i = 0;
    }
}
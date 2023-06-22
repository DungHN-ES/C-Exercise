#include "stdio.h"

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int b = 16;
    int n = 1231412;
    char s[1024];

    itob(n,s,b);
    printf("%s\n", s);
    return 0;
}

void itob(int n, char s[], int b)
{
    int i = 0;
    int sign = '+';
    if (n < 0)
    {
        sign = '-';
        n = - n;
    }

    do
    {
        int tmp = n % b;
        s[i++] = (tmp <= 9) ? '0' + tmp : 'A' + tmp - 10;
    } while ((n /= b) != 0);

    if (sign == '-')
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int i = 0, j = strlen(s) - 1;
    int tmp;
    while (i < j)
    {
        tmp = s[i], s[i] = s[j], s[j] = tmp;
        ++i;
        --j;
    }
}
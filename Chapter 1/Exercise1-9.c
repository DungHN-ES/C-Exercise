#include "stdio.h"

int main()
{
    int flag = 0;
    int c;
    
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' && flag == 0)
        {
            flag = 1;
            putchar(c);
        }
        else if (c == ' ' && flag == 1)
        {
            continue;
        }
        else if (c != ' ')
        {
            flag = 0;
            putchar(c);
        }
    }
    return 0;
}
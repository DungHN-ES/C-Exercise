#include <stdio.h>
#include <stdarg.h>

void scanf_m(char *fmt, ...);

int main(int argc, char *argv[])
{
    int x;
    char str[100];
    scanf_m("%s %d", str, &x);
    printf("You have entered: %s %d\n", str, x);
    return 0;
}

void scanf_m(char *fmt, ...)
{
    va_list argument_pointer;
    va_start(argument_pointer, fmt);

    int c;
    char *p;
    int *intValue = NULL;
    double *doubleValue = NULL;
    char *charValue = NULL;

    for (p = fmt; *p != '\0'; ++p)
    {
        if (*p != '%')
            continue;
        switch(*++p)
        {
            case 'd':
                intValue = va_arg(argument_pointer, int*);
                scanf("%d", intValue);
                break;
            case 'c':
                charValue = va_arg(argument_pointer, char*);
                scanf("%c", charValue);
                break;
            case 'f':
                scanf("%lf", va_arg(argument_pointer, double*));
                break;
            case 'i':
                scanf("%i", va_arg(argument_pointer, int*));
                break;
            case 'o':
                scanf("%o", va_arg(argument_pointer, int*));
                break;
            case 's':
                charValue = va_arg(argument_pointer, char*);
                scanf("%s", charValue);
                break;
        }
    }
    va_end(argument_pointer);
}
#include <stdarg.h>
#include <stdio.h>

void printf_m(char *fmt, ...);

int main()
{
    int x = 999;
    double y = 123.43;
    char  str = '#';
    printf_m("%c abc 123 %d abc %f\n\n",str, x, y);
    return 0;
}

void printf_m(char *fmt, ...)
{
    va_list arg_pointer;
    va_start(arg_pointer, fmt);
    
    char *p, *strVal;
    int dVal, c;
    double fVal;

    for (p = fmt; *p != '\0'; p++)
    {
        if (*p != '%')
        {
            putchar(*p);
            continue;
        }

        switch(*++p)
        {
            case 'd':
                dVal = va_arg(arg_pointer, int);
                printf("%d", dVal);
                break;
            case 'f':
                fVal = va_arg(arg_pointer, double);
                printf("%f", fVal);
                break;
            case 'c':
                c = va_arg(arg_pointer,int);
                putchar(c);
                break;
            case 's':
                for (strVal = va_arg(arg_pointer, char *); *strVal != '\0'; strVal++)
                    putchar(*strVal);
                break;
            default:
                break;
        }
    }
    va_end(arg_pointer);
}


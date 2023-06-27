/*
Exercise 4-2. Extend atof to handle scientific notation of the form 
    123.45e-6
where a floating point number may be followed by e or E and an optionally
signed exponent.
*/

#include "stdio.h"
#include <ctype.h>

double extended_atof(char *str);
double atof(char *str);
double power(double x, double y);

int main() {
    char *str = "  123.45e6";
    printf("%s = %.9f\n", str, extended_atof(str));
    return 0;
}

double extended_atof(char *str)
{


    int i, esign, exp = 0;
    double decVal = 0;

    for (i = 0; isdigit(str[i]) == 0; ++i)
        ;
    while (isdigit(str[i]))
        decVal = 10 * decVal + str[i++] - '0';
    
    i++;

    int count = 1;
    while (isdigit(str[i]) != 0)
    {
        decVal = 10 * decVal + str[i++] - '0';
        count *= 10;
    }
    
    decVal = decVal / count;

    if (str[++i] == '-')
    {
        esign = -1;
        i++;
    }

    while (str[i] != '\0')
        exp = exp * 10 + str[i++] - '0';

    if (esign == -1)
        return decVal/power(10,exp);
    else return decVal * power(10, exp);

}

double atof(char *str)
{
    int i;
    double decVal = 0;

    for (i = 0; isdigit(str[i]) == 0; ++i)
        ;
    while (isdigit(str[i]))
        decVal = 10 * decVal + str[i++] - '0';
    
    i++;

    int count = 1;
    while (isdigit(str[i]) != 0)
    {
        decVal = 10 * decVal + str[i++] - '0';
        count *= 10;
    }
    return decVal / count;
}

double power(double x, double y)
{
    double ans = 1;
    if (y == 0) return 1;
    else
    {
        while (y-- > 0)
            ans = ans * x;
    }
    return ans;
}
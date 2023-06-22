#include <stdio.h>
#include <ctype.h>

double myatof(char s[]);
double atof_m(char s[]);
double power(int b, int exp);
double exponential(double, double);

int main()
{
    int b = 2;
    int exp = 3;
    char s[] = "-13.2e-3";
    printf("%f\n", myatof(s));

    return 0;

}

double myatof(char s[])
{
    char tmp[1000];
    double tmp2, expo = 0;
    int i, esign;
    double exponential(double, double);

    for (i = 0; s[i] != 'e' && s[i] != 'E'; ++i)
    {
        tmp[i] = s[i];
    }
    tmp[i] = '\0';

    tmp2 = atof_m(tmp);
    
    i++;

    esign = (s[i] == '-') ? -1 : 1;

    if (esign == -1)
    i++;

    
    while (s[i] != '\0')
    {
        expo = expo * 10.0 + s[i] - '0';
        ++i;
    }
   
    if (esign == 1)
        return tmp2 * exponential(10, expo);
    else 
        return tmp2 / exponential(10, expo);

}
double exponential(double base, double exp)
{
    double ans = 1;
    if (exp == 0)   return 1;
    for (int i = 1; i <= exp; ++i)
    {
        ans = ans * base;
    }
    return  ans;
}
double atof_m(char s[])
{
    int i, sign, expo;
    double val;

    for (i = 0; isspace(s[i]); ++i)
        ;
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); ++i)
        val = val * 10 + s[i] - '0';
    i++;
    for (expo = 1; isdigit(s[i]); ++i, expo *= 10)
        val = val * 10 + s[i] - '0';

    return sign * val / expo;
}






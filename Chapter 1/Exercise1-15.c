#include "stdio.h"

float fahrenheit2Celcius(float);

int main()
{
    float c;
    scanf("%f", &c);
    printf("%.2f degree F = %.2f degree C", c, fahrenheit2Celcius(c));
    return 0;
}

float fahrenheit2Celcius(float degree)
{
    return 5 * (degree-32)/9;
}
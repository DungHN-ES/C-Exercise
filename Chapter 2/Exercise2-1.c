#include <stdio.h>
#include <limits.h>

int main()
{
    printf("According the standard header limits.h\n");
    printf("The minimum value for type char: %d\n", CHAR_MIN);
    printf("The maximum value for type char: %d\n", CHAR_MAX);
    printf("The minimum value for type int: %d\n", INT_MIN);
    printf("The maximum value for type int: %d\n", INT_MAX);
    printf("The minimum value for type short: %d\n", SHRT_MIN);
    printf("The maximum value for type short: %d\n", SHRT_MAX);
    printf("The minimum value for type long: %ld\n", LONG_MIN);
    printf("The maximum value for type long: %ld\n", LONG_MAX);
    return 0;
}
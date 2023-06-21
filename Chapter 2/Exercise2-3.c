#include "stdio.h"
#include "math.h"
#include "string.h"

#define MAX_LEN 1000

unsigned long int htoi(char hexString[]);

int main()
{
    char hexString[MAX_LEN] = "0x0F21A";
    printf("Hexadecimal string: %s\n", hexString);
    printf("Decimal value: %ld\n", htoi(hexString));
    return 0;
}

unsigned long int htoi(char hex[])
{
    int hexLen = strlen(hex);
    int decValue = 0;
    
    for (int i = 0; hex[hexLen-1] != 'x' && hex[hexLen-1] != 'X'; ++i)
    {
        if (hex[hexLen-1] >= '0' && hex[hexLen-1] <= '9')
            decValue = decValue + (hex[hexLen-1] - '0')*(int)pow(16,i);
        if (hex[hexLen-1] >= 'a' && hex[hexLen-1] <= 'f')
            decValue = decValue + (hex[hexLen-1] - 'a' + 10)*(int)pow(16,i);
        if (hex[hexLen-1] >= 'A' && hex[hexLen-1] <= 'F')
            decValue = decValue + (hex[hexLen-1] - 'A' + 10)*(int)pow(16,i);
        --hexLen;
    }
    return decValue;
}
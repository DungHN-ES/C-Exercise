#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (!strcmp(argv[1], "2lower"))
            putchar(tolower(c));
        else if (!strcmp(argv[1], "2upper"))
            putchar(toupper(c));
        else 
            printf("Undefined syntax!\n");
    }
    return 0;
}
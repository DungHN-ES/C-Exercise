#include <stdio.h>
#include <ctype.h>

#define _MAX_LEN 14
#define _CNTRL_CHAR_LEN 6 /* format <0x00>*/

int main()
{
    int c, pos = 0;

    while ((c = getchar()) != EOF)
    {
        if (pos <= _MAX_LEN)
        {
            if (iscntrl(c) || c == ' ')
            {
                if (pos + _CNTRL_CHAR_LEN <= _MAX_LEN)
                {
                    pos += _CNTRL_CHAR_LEN;
                    printf("<0x%02x>", c);
                }
                else
                {
                    putchar('\n');
                    pos = _CNTRL_CHAR_LEN;
                    printf("<0x%02x>", c);
                }
            }
            else
            {
                if (pos + 1 <= _MAX_LEN)
                {
                    pos++;
                    putchar(c);
                }
                else
                {
                    pos = 1;
                    putchar('\n');
                    putchar(c);
                }
            }
        }
        else
        {
            pos = 0;
            putchar('\n');
            putchar(c);
            pos++;
        }
    }
}
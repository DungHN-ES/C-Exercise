#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#define _MAX_VAL 100

int stack_pos = 0;
double cal[_MAX_VAL];

void push(double);
double pop(void);

int main()
{
    char s[_MAX_VAL], c;
    double num, op2;

    while (scanf("%s%c", s, &c) == 2)
    {
        if (sscanf(s, "%lf", &num) == 1)
            push(num);
        else if (strlen(s) == 1)
        {
            switch (s[0])
            {
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                push(pop() / op2);
                break;
            default:
                printf("Unknow operator: %s\n", s);
                c = ' ';
                break;
            }
        }
        if (c == '\n')
            printf("%lf\n", pop());
    }
    return 0;
}
/* push a float into stack */
void push(double value)
{
    if (stack_pos >= _MAX_VAL)
        printf("The stack is full\n");
    else
        cal[stack_pos++] = value;
}

/* pop a value from top of stack */
double pop(void)
{
    if (!stack_pos)
    {
        printf("The stack is empty!\n");
        return 0.0;
    }
    else
    {
        stack_pos--;
        return cal[stack_pos];
    }
}
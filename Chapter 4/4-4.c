#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define _BUFF_SIZE 100
#define _MAX_VAL 100
#define NUMBER '0'
#define _MAX_OP_SIZE 100

char buffer[_BUFF_SIZE]; // buffer for ungetch
int buffer_pos = 0; // next free position in buffer
int stack_pos = 0;
double cal[_MAX_VAL];

int getch(void);
void ungetch(int c);
int getop(char []);
void push(double);
double pop(void);
void printStack(void);

int main()
{
    int type;
    double op2;
    char inputString[_MAX_OP_SIZE];

    while ((type = getop(inputString)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(inputString));
            break;
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
            if (!op2)
                printf("Error: Divisor by 0\n");
            else
            {
                push(pop() / op2);
            }
            break;
        /* Add the modulus (%) operator */
        case '%':   
            op2 = pop();
            if (!op2)
                printf("Error: Divisor by 0\n");
            else
                push((int)pop() % (int)op2);
            break;
        /* Print the top element without poping */
        case 'p':
            printf("%f\n", cal[stack_pos-1]);
            break;
        /* Duplicate the top element */
        case 'd':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        /* Swap the position of top two elements */
            double op1 = pop();
            op2 = pop();
            push(op1);
            push(op2);
            break;
        /* Clear the stack */
        case 'c':
            stack_pos = 0;
            break;
        case '\n':
            printf("%f\n", pop());
            break;
        default:
            break;
        }
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

/* get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || s[0] == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.') // If c is operator
    {
        return c;
    }
    i = 0;
    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()));
    }
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

/* get or push back a character */
int getch(void)
{
    return (buffer_pos > 0) ? buffer[--buffer_pos] : getchar();
}

/* push character back on input buffer */
void ungetch(int c)
{
    if (buffer_pos < _BUFF_SIZE)
        buffer[buffer_pos++] = c;
    else
        printf("The buffer is full\n");
    
}
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0'
#define BUFSIZE 100


int sp = 0;
double stack[MAXOP];
char buf[BUFSIZE];
int bufp = 0;

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
            case '0':
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 == 0)
                    printf("Error: Divisor is zero!\n");
                else
                    push(pop() / op2);
                break;
            case '\n':
                printf("\t\t%f\n\n", pop());
                break;
            default:
                printf("error");
                break;
        }
    }
    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp == MAXOP)
    {
        printf("Stack is full!\n");
    }
    else
        stack[sp++] = f;
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    else
    {
        printf("Stack is empty\n");
        return -1;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;   /* not a number */
    i = 0;

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    
    return '\0';
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ERROR");
    else
        buf[bufp++] = c;
}
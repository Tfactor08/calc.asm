#include <stdio.h>
#include <stdlib.h> // for atof()
#include <string.h>

#define OUT

#define MAXOP  100
#define NUMBER '0'

int  getop(char [], char []);
void push(int);
int  pop();

extern int op_add(int, int);
extern int op_mul(int, int);
extern int op_sub(int, int);

/* revise the calculator to use getline to read an entire input line */
int main()
{
    int type, r, _;
    int op2;
    char *l = NULL;
    char s[MAXOP];

    while (getline(&l, &_, stdin) != -1) {
        while ((type = getop(l, s)) != -1) {
            switch (type) {
                case NUMBER:
                    push(atof(s));
                    break;
                case '+':
                    r = op_add(pop(), pop());
                    push(r);
                    break;
                case '*':
                    r = op_mul(pop(), pop());
                    push(r);
                    break;
                case '-':
                    op2 = pop();
                    r = op_sub(pop(), op2);
                    push(r);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("ERROR: zero divisor\n");
                    break;
                case '\n':
                    printf("\t%d\n", pop());
                    break;
                default:
                    printf("ERROR: unknown command %s\n", s);
                    break;
            }
        }
    }
    return 0;
}

#define MAXVAL 100

int sp = 0;
int val[MAXVAL];

void push(int d)
{
    if (sp < MAXVAL)
        val[sp++] = d;
    else
        printf("ERROR: stack overflow, can't push %g\n", d);
}

int pop()
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("ERROR: stack underflow\n");
        return 0.0;
    }
}

#include <ctype.h>

/* getop: get next operator or numeric operand */
int getop(char line[], OUT char s[])
{
    static int i;
    int c;

    if (i == strlen(line)) { // line is read
        i = 0;
        return -1;
    }

    while ((s[0] = c = line[i++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c))
        return c;   // not a number
    int j = 0;
    if (isdigit(c)) // collect integer
        while (isdigit(s[++j] = c = line[i++]))
            ;
    s[j] = '\0';
    i--; // otherwise, first non-digit char will be skipped 

    return NUMBER;
}

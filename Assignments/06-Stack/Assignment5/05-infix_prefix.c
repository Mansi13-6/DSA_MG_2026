#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct stack
{
    char arr[MAX];
    int top;

} stack_t;

void init_stack(stack_t *s)
{
    s->top = -1;
}

void push(stack_t *s, char ch)
{
    s->arr[++s->top] = ch;
}

char pop(stack_t *s)
{
    return s->arr[s->top--];
}

char peek(stack_t *s)
{
    return s->arr[s->top];
}

int is_empty(stack_t *s)
{
    return s->top == -1;
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    return 0;
}

/* reverse string */

void reverse(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

/* main function */

int main()
{
    stack_t s;

    char infix[] = "F*(A+B)/E-D*(G+H/K)";
    char postfix[MAX];
    char prefix[MAX];

    int i, j = 0;

    reverse(infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';

        else if (infix[i] == ')')
            infix[i] = '(';
    }

    init_stack(&s);

    for (i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&s, ch);
        }
        else if (ch == ')')
        {
            while (peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }

            pop(&s);
        }
        else
        {
            while (!is_empty(&s) &&
                   precedence(peek(&s)) >= precedence(ch))
            {
                postfix[j++] = pop(&s);
            }

            push(&s, ch);
        }
    }

    while (!is_empty(&s))
    {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';

    reverse(postfix);

    strcpy(prefix, postfix);

    printf("Prefix Expression : %s\n", prefix);

    return 0;
}
#include <stdio.h>
#include <string.h>

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

int is_empty(stack_t *s)
{
    return s->top == -1;
}


void push(stack_t *s, char ch)
{
    s->arr[++s->top] = ch;
}

char pop(stack_t *s)
{
    return s->arr[s->top--];
}


int is_matching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    return 0;
}

int main()
{
    stack_t s;
    char exp[MAX];
    char ch, temp;
    int i;

    init_stack(&s);

    printf("Enter Expression : ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(&s, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (is_empty(&s))
            {
                printf("Expression is Not Balanced\n");
                return 0;
            }

            temp = pop(&s);

            if (!is_matching(temp, ch))
            {
                printf("Expression is Not Balanced\n");
                return 0;
            }
        }
    }

    if (is_empty(&s))
    {
        printf("Expression is Balanced\n");
    }
    else
    {
        printf("Expression is Not Balanced\n");
    }

    return 0;
}
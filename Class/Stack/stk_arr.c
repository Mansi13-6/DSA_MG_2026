#include <stdio.h>

/*symbolic constants*/

#define MAX 5
#define SUCCESS 1
#define FAILURE 0

/* stack structure*/

typedef struct stack
{
    int arr[MAX];
    int top;

} stack_t;

/* initialize stack*/
void init_stack(stack_t *s)
{
    s->top = -1;
}

/* check stack full*/
int is_full(stack_t *s)
{
    return s->top == MAX - 1;
}

/*check stack empty*/
int is_empty(stack_t *s)
{
    return s->top == -1;
}

/*push operation*/
int push(stack_t *s, int data)
{
    if (is_full(s))
    {
        return FAILURE;
    }

    s->arr[++s->top] = data;

    return SUCCESS;
}

/*pop operatiom*/

int pop(stack_t *s, int *deleted_data)
{
    if (is_empty(s))
        return FAILURE;

    *deleted_data = s->arr[s->top--];

    return SUCCESS;
}

/*peekoperation*/
int peek(stack_t *s, int *top_data)
{
    if (is_empty(s))
        return FAILURE;

    *top_data = s->arr[s->top];

    return SUCCESS;
}

/*display stack*/

void display(stack_t *s)
{
    if (is_empty(s))
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("\n TOP->");

    for (int i = s->top; i >= 0; i--)
    {
        printf("[%d]", s->arr[i]);
    }

    printf("\n");
}

/* main function*/
int main()
{
    stack_t s;
    int data;

    init_stack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    if (peek(&s, &data) == SUCCESS)
        printf("\n Top Element:%d\n", data);

    if (pop(&s, &data) == SUCCESS)
        printf("\n Deleted Element:%d\n", data);

    display(&s);

    return 0;
}
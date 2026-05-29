#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct node
{
    int data;
    struct node *next;

} node_t;

node_t *top = NULL;

int is_empty()
{
    return top == NULL;
}


int push(int data)
{
    node_t *newnode;

    newnode = (node_t *)malloc(sizeof(node_t));

    if (newnode == NULL)
    {
        return FAILURE;
    }

    newnode->data = data;

    newnode->next = top;

    top = newnode;

    return SUCCESS;
}


int pop(int *deleted_data)
{
    node_t *temp;

    if (is_empty())
    {
        return FAILURE;
    }

    temp = top;

    *deleted_data = top->data;

    top = top->next;

    free(temp);

    return SUCCESS;
}


int peek(int *top_data)
{
    if (is_empty())
    {
        return FAILURE;
    }

    *top_data = top->data;

    return SUCCESS;
}


void display()
{
    node_t *temp;

    if (is_empty())
    {
        printf("Stack is Empty\n");
        return;
    }

    temp = top;

    printf("\nTOP->");

    while (temp != NULL)
    {
        printf("[%d]", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int data;

    if (push(10) == SUCCESS)
        printf("10 inserted successfully\n");

    if (push(20) == SUCCESS)
        printf("20 inserted successfully\n");

    if (push(30) == SUCCESS)
        printf("30 inserted successfully\n");

    display();

    if (peek(&data) == SUCCESS)
        printf("\nTop Element: %d\n", data);

    if (pop(&data) == SUCCESS)
        printf("\nDeleted Element: %d\n", data);

    display();

    return 0;
}
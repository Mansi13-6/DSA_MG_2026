#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} node_t;

node_t *create(node_t *head, int n)
{
    int value;
    node_t *newnode;

    if (n == 0)
    {
        return NULL;
    }

    newnode = (node_t *)malloc(sizeof(node_t));

    printf("Enter data : ");
    scanf("%d", &value);

    newnode->data = value;

    newnode->next = create(head, n - 1);

    return newnode;
}

void display(node_t *head)
{
    if (head == NULL)
    {
        return;
    }

    printf("%d --> ", head->data);

    display(head->next);
}

int main()
{
    node_t *head = NULL;

    int n;

    printf("Enter number of nodes : ");
    scanf("%d", &n);

    head = create(head, n);

    display(head);

    printf("NULL\n");

    return 0;
}
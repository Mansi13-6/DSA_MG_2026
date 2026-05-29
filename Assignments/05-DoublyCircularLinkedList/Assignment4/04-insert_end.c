#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;

} node_t;

node_t *head = NULL;

void create(int value)
{
    node_t *newnode, *temp;

    newnode = (node_t *)malloc(sizeof(node_t));

    newnode->data = value;

    if (head == NULL)
    {
        head = newnode;

        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        temp = head->prev;

        temp->next = newnode;

        newnode->prev = temp;
        newnode->next = head;

        head->prev = newnode;
    }
}

void insert_last(int value)
{
    node_t *newnode, *last;

    newnode = (node_t *)malloc(sizeof(node_t));

    newnode->data = value;

    last = head->prev;

    last->next = newnode;

    newnode->prev = last;
    newnode->next = head;

    head->prev = newnode;
}

void display()
{
    node_t *temp;

    temp = head;

    do
    {
        printf("%d <--> ", temp->data);

        temp = temp->next;

    } while (temp != head);

    printf("HEAD\n");
}

int main()
{
    int n, i, value;

    printf("Enter number of nodes : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter data : ");
        scanf("%d", &value);

        create(value);
    }

    display();

    printf("Enter value : ");
    scanf("%d", &value);

    insert_last(value);

    display();

    return 0;
}
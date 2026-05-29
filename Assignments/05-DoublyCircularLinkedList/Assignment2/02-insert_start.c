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

void insert_begin(int value)
{
    node_t *newnode, *last;

    newnode = (node_t *)malloc(sizeof(node_t));

    newnode->data = value;

    last = head->prev;

    newnode->next = head;
    newnode->prev = last;

    last->next = newnode;

    head->prev = newnode;

    head = newnode;
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
    create(10);
    create(20);
    create(30);

    insert_begin(5);

    display();

    return 0;
}
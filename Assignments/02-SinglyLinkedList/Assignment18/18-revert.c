#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    char name[20];
    struct node *next;

} node_t;

node_t *head = NULL;

void create(int data, char name[])
{
    node_t *newnode, *temp;

    newnode = (node_t *)malloc(sizeof(node_t));

    newnode->data = data;
    strcpy(newnode->name, name);

    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void reverse_list()
{
    node_t *prev, *current, *nextnode;

    prev = NULL;
    current = head;

    while (current != NULL)
    {
        nextnode = current->next;

        current->next = prev;

        prev = current;

        current = nextnode;
    }

    head = prev;
}

void display()
{
    node_t *temp;

    temp = head;

    while (temp != NULL)
    {
        printf("|_%d_|_%s_| --> ",
               temp->data,
               temp->name);

        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int n, i, data;
    char name[20];

    printf("Enter number of nodes : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter data and name : ");
        scanf("%d %s", &data, name);

        create(data, name);
    }

    printf("\nOriginal List:\n");
    display();

    reverse_list();

    printf("\nReversed List:\n");
    display();

    return 0;
}
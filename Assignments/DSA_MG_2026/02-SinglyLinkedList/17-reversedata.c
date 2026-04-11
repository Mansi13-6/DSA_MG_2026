#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    char name[50];
    struct node *next;
} node;

node *create(node *head);
void display(node *head);
void display_reverse(node *head);

int main()
{
    node *head = NULL;

    head = create(head);

    printf("\nOriginal List:\n");
    display(head);

    printf("\nReverse Order:\n");
    display_reverse(head);
    printf("NULL\n");

    return 0;
}

node *create(node *head)
{
    node *temp, *last = NULL;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));

        printf("Enter data and name: ");
        scanf("%d %s", &temp->data, temp->name);

        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }

    return head;
}

void display(node *head)
{
    node *p = head;

    while (p != NULL)
    {
        printf("%d %s -> ", p->data, p->name);
        p = p->next;
    }
    printf("NULL\n");
}

void display_reverse(node *head)
{
    if (head == NULL)
        return;

    display_reverse(head->next);
    printf("%d %s -> ", head->data, head->name);
}
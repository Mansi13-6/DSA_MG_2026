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
node *concatenate(node *head1, node *head2);

int main()
{
    node *head1 = NULL, *head2 = NULL, *head3 = NULL;

    printf("Create List 1:\n");
    head1 = create(head1);

    printf("\nCreate List 2:\n");
    head2 = create(head2);

    printf("\nList 1:\n");
    display(head1);

    printf("\nList 2:\n");
    display(head2);

    head3 = concatenate(head1, head2);

    printf("\nAfter Concatenation (List1 + List2):\n");
    display(head3);

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
node *concatenate(node *head1, node *head2)
{
    if (head1 == NULL)
        return head2;

    node *p = head1;
    while (p->next != NULL)
        p = p->next;
    p->next = head2;

    return head1;
}
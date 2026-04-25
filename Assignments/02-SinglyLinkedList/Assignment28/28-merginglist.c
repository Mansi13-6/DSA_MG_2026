#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct singlyLL
{
    int data;
    char name[50];
    struct singlyLL *next;
} sl;

sl *create(sl *head);
void display(sl *head);
sl *merge(sl *head1, sl *head2);

int main()
{
    sl *head1 = NULL, *head2 = NULL;

    printf("Create List 1:\n");
    head1 = create(head1);

    printf("\nCreate List 2:\n");
    head2 = create(head2);

    printf("\nList 1:\n");
    display(head1);

    printf("\nList 2:\n");
    display(head2);

    head1 = merge(head1, head2);

    printf("\nMerged List (List1 + List2):\n");
    display(head1);

    return 0;
}
sl *create(sl *head)
{
    sl *temp, *last = NULL;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        temp = (sl *)malloc(sizeof(sl));

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

void display(sl *head)
{
    sl *p = head;

    while (p != NULL)
    {
        printf("%d %s -> ", p->data, p->name);
        p = p->next;
    }
    printf("NULL\n");
}
sl *merge(sl *head1, sl *head2)
{
    if (head1 == NULL)
        return head2;
    sl *p = head1;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = head2;

    return head1;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(node *head);
void display(node *head);
void find_middle(node *head);

int main()
{
    node *head = NULL;

    head = create(head);

    printf("\nLinked List:\n");
    display(head);

    find_middle(head);

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
        printf("Enter data: ");
        scanf("%d", &temp->data);

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
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void find_middle(node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    node *slowptr = head;
    node *fastptr = head;
    while (fastptr != NULL && fastptr->next != NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }

    printf("\nMiddle element = %d\n", slowptr->data);
}
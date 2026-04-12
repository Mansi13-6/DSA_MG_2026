#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create(node *head);
void display(node *head);
int count_nodes(node *head);

int main()
{
    node *head = NULL;
    int count;

    head = create(head);

    printf("\nLinked List:\n");
    display(head);

    count = count_nodes(head);

    printf("\nNumber of nodes in the list = %d\n", count);

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

int count_nodes(node *head)
{
    int count = 0;
    node *p = head;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}
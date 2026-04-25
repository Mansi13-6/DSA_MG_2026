#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLL
{
    int data;
    struct singlyLL *next;
} sl;

sl *create(sl *head);
void display(sl *head);
int count_nodes(sl *head);

int main()
{
    sl *head = NULL;
    int count;

    head = create(head);

    printf("\nLinked List:\n");
    display(head);

    count = count_nodes(head);

    printf("\nNumber of nodes in the list = %d\n", count);

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

void display(sl *head)
{
    sl *p = head;

    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int count_nodes(sl *head)
{
    int count = 0;
    sl *p = head;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} sl;

sl *create(sl *head);
void display(sl *head);
void find_middle(sl *head);

int main()
{
    sl *head = NULL;

    head = create(head);

    printf("\nLinked List:\n");
    display(head);

    find_middle(head);

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

void find_middle(sl *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    sl *slowptr = head;
    sl *fastptr = head;
    while (fastptr != NULL && fastptr->next != NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }

    printf("\nMiddle element = %d\n", slowptr->data);
}
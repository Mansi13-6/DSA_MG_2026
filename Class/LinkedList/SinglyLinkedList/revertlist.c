#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

node* create(node *head)
{
    node *temp, *last = NULL;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        temp = (node*)malloc(sizeof(node));

        printf("Enter data: ");
        scanf("%d", &temp->data);

        temp->next = NULL;

        if(head == NULL)
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

void display(node *p)
{
    if(p == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }

    printf("NULL\n");
}

node* revert_list(node* head)
{
    node *p, *q, *r;

    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    r = NULL;
    p = head;
    q = head->next;

    while(q != NULL)
    {
        p->next = r;
        r = p;
        p = q;
        q = q->next;
    }

    p->next = r;
    head = p;

    return head;
}

int main()
{
    node *head = NULL;

    head = create(head);

    printf("\nOriginal List:\n");
    display(head);

    head = revert_list(head);

    printf("\nReversed List:\n");
    display(head);

    return 0;
}
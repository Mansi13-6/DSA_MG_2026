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
    sl *head1 = NULL;
    sl *head2 = NULL;
    sl *head3 = NULL;

    printf("Create List 1:\n");
    head1 = create(head1);

    printf("\nCreate List 2:\n");
    head2 = create(head2);

    printf("\nList 1:\n");
    display(head1);

    printf("\nList 2:\n");
    display(head2);

    head3 = merge(head1, head2);

    printf("\nMerged Sorted List:\n");
    display(head3);

    return 0;
}

sl *create(sl *head)
{
    sl *temp, *last = NULL;
    int ch;

    do
    {
        temp = (sl *)malloc(sizeof(sl));

        printf("Enter data and name: ");
        scanf("%d %s",
              &temp->data,
              temp->name);

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

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &ch);

    } while (ch != 0);

    return head;
}

void display(sl *head)
{
    sl *p = head;

    while (p != NULL)
    {
        printf("|_%d_|_%s_| --> ",
               p->data,
               p->name);

        p = p->next;
    }

    printf("NULL\n");
}

sl *merge(sl *head1, sl *head2)
{
    sl *head3 = NULL;
    sl *last = NULL;
    sl *newnode;

    while (head1 != NULL && head2 != NULL)
    {
        newnode = (sl *)malloc(sizeof(sl));

        if (head1->data < head2->data)
        {
            newnode->data = head1->data;
            strcpy(newnode->name, head1->name);

            head1 = head1->next;
        }
        else
        {
            newnode->data = head2->data;
            strcpy(newnode->name, head2->name);

            head2 = head2->next;
        }

        newnode->next = NULL;

        if (head3 == NULL)
        {
            head3 = newnode;
            last = newnode;
        }
        else
        {
            last->next = newnode;
            last = newnode;
        }
    }

    while (head1 != NULL)
    {
        newnode = (sl *)malloc(sizeof(sl));

        newnode->data = head1->data;
        strcpy(newnode->name, head1->name);

        newnode->next = NULL;

        last->next = newnode;
        last = newnode;

        head1 = head1->next;
    }

    while (head2 != NULL)
    {
        newnode = (sl *)malloc(sizeof(sl));

        newnode->data = head2->data;
        strcpy(newnode->name, head2->name);

        newnode->next = NULL;

        last->next = newnode;
        last = newnode;

        head2 = head2->next;
    }

    return head3;
}
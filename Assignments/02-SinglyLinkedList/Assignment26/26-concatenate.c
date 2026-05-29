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
sl *concatenate(sl *head1, sl *head2);

int main()
{
    sl *head1 = NULL;
    sl *head2 = NULL;
    sl *head3 = NULL;

    printf("Create List 1\n");
    head1 = create(head1);

    printf("\nCreate List 2\n");
    head2 = create(head2);

    printf("\nList 1:\n");
    display(head1);

    printf("\nList 2:\n");
    display(head2);

    head3 = concatenate(head1, head2);

    printf("\nConcatenated List:\n");
    display(head3);

    return 0;
}

sl *create(sl *head)
{
    sl *newnode, *temp;
    int choice;

    do
    {
        newnode = (sl *)malloc(sizeof(sl));

        printf("Enter data and name : ");
        scanf("%d %s",
              &newnode->data,
              newnode->name);

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

        printf("Do you want to continue ? ");
        scanf("%d", &choice);

    } while (choice == 1);

    return head;
}

void display(sl *head)
{
    sl *temp;

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

sl *concatenate(sl *head1, sl *head2)
{
    sl *head3 = NULL;
    sl *temp, *newnode, *last = NULL;

    temp = head1;

    while (temp != NULL)
    {
        newnode = (sl *)malloc(sizeof(sl));

        newnode->data = temp->data;
        strcpy(newnode->name, temp->name);

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

        temp = temp->next;
    }

    temp = head2;

    while (temp != NULL)
    {
        newnode = (sl *)malloc(sizeof(sl));

        newnode->data = temp->data;
        strcpy(newnode->name, temp->name);

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

        temp = temp->next;
    }

    return head3;
}
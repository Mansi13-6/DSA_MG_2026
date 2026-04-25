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
void sort_list(sl *head);

int main()
{
    sl *head = NULL;

    head = create(head);

    printf("\nOriginal List:\n");
    display(head);

    sort_list(head);

    printf("\nSorted List (Ascending Order):\n");
    display(head);

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
        temp = (sl*)malloc(sizeof(sl));

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

void sort_list(sl *head)
{
    sl *i, *j;
    int temp_data;
    char temp_name[50];

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp_data = i->data;
                i->data = j->data;
                j->data = temp_data;

                strcpy(temp_name, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, temp_name);
            }
        }
    }
}
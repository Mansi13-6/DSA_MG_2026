#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    char name[50];
    struct node *next;
} sl;

sl *create(sl *head);
void display(sl *head);
sl *delete_at_head(sl *head);

int main()
{
    sl *head = NULL;

    head = create(head);

    printf("\nOriginal List:");
    display(head);

    head = delete_at_head(head);

    printf("\nAfter Deleting at Head:");
    display(head);

    return 0;
}

sl *create(sl *head)
{
    sl *temp, *last = NULL;
    int i;

    for (i = 0; i < 5; i++)
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
    printf("\nLinked List:\n");

    while (p != NULL)
    {
        printf("%d %s -> ", p->data, p->name);
        p = p->next;
    }
    printf("NULL\n");
}

sl *delete_at_head(sl *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    sl *temp = head;
    head = head->next;
    free(temp);

    return head;
}
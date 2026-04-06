#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct singlyLL
{
    int data;
    char name[50];
    struct singlyLL *next;
}sl;

sl *create (sl *head);
void display (sl *head);
sl *insert_at_pos(sl *head, int pos, int data, char name[]);

int main()
{
    sl *head = NULL;
    int data, pos;
    char name[50];

    head = create(head);

    printf("\nOriginal List:");
    display(head);

    printf("\nEnter position: ");
    scanf("%d", &pos);

    printf("Enter data and name: ");
    scanf("%d %s", &data, name);

    head = insert_at_pos(head, pos, data, name);

    printf("\nAfter inserting at position:");
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
        printf("Enter the data and name: ");
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

sl *insert_at_pos(sl *head, int pos, int data, char name[])
{
    sl *new_node = (sl *)malloc(sizeof(sl));

    new_node->data = data;
    strcpy(new_node->name, name);
    if (pos == 1)
    {
        new_node->next = head;
        return new_node;
    }

    sl *p = head;
    for (int i = 1; i < pos - 1 && p != NULL; i++)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    new_node->next = p->next;
    p->next = new_node;

    return head;
}
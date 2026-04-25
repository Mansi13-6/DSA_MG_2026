#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct singlyLL
{
    int data;
    char name[50];
    struct singlyLL *next;
}sl;

sl *create(sl *head);
void display(sl *head);
sl *insert_at_end(sl *head, int data, char name[]);

int main()
{
    sl *head = NULL;
    int data;
    char name[50];
    head = create(head);

    printf("\nOriginal List:");
    display(head);

    printf("\nEnter data and name to insert at end: ");
    scanf("%d %s", &data, name);

    head = insert_at_end(head, data, name);

    printf("\nAfter inserting at end:");
    display(head);

    return 0;
}

sl* create(sl *head) 
{
    sl *temp, *last = NULL;
    int i, n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        temp = (sl*)malloc(sizeof(sl));

        if(temp == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        printf("Enter the data and name: ");
        scanf("%d %s", &temp->data, temp->name);

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

sl *insert_at_end(sl *head, int data, char name[])
{
    sl *new_node = (sl *)malloc(sizeof(sl));

    new_node->data = data;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    if (head == NULL)
    {
        return new_node;
    }
    sl *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = new_node;

    return head;
}
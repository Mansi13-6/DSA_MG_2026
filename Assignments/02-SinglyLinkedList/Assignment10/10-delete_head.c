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
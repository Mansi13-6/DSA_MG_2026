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
sl *delete_by_key(sl *head, int key);

int main()
{
    sl *head = NULL;
    int key;

    head = create(head);

    printf("\nOriginal List:");
    display(head);

    printf("\nEnter key to delete: ");
    scanf("%d", &key);

    head = delete_by_key(head, key);

    printf("\nAfter Deletion:");
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

sl *delete_by_key(sl *head, int key)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->data == key)
    {
        sl *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    sl *p = head;

    while (p->next != NULL && p->next->data != key)
    {
        p = p->next;
    }

    if (p->next == NULL)
    {
        printf("Key not found!\n");
        return head;
    }

    sl *temp = p->next;
    p->next = temp->next;
    free(temp);

    return head;
}
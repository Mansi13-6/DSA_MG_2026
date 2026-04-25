#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct singlyLL
{
    int data;
    char name[10];
    struct singlyLL *next;
} sl;

sl *create(sl *head);
void search(sl *head, int key);
void display(sl *head);

int main()
{
    sl *head = NULL;
    int key;
    head = create(head);
    printf("Enter element to search: ");
    scanf("%d", &key);
    search(head, key);
    display(head);
    return 0;
}

sl *create(sl *head)
{
    sl *temp, *last = NULL;
    int i, n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        temp = (sl *)malloc(sizeof(sl));

        if (temp == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

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

void search(sl *head, int key)
{
    sl *p = head;
    int position = 1;
    while (p != NULL)
    {
        if (p->data == key)
        {
            printf("Found at position %d: %d %s\n", position, p->data, p->name);
            return;
        }
        p = p->next;
        position++;
    }
    printf("Element not found");
}
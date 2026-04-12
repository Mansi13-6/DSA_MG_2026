#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    char name[50];
    struct node *next;
} node;

node *create(node *head);
void display(node *head);
node *insert_before_key(node *head, int key, int value, char name[]);

int main()
{
    node *head = NULL;
    int key, value;
    char name[50];

    head = create(head);

    printf("\nOriginal List:\n");
    display(head);

    printf("Enter key, data and name to insert before: ");
    scanf("%d %d %s", &key, &value, name);

    head = insert_before_key(head, key, value, name);

    printf("\nUpdated List:\n");
    display(head);

    return 0;
}

node *create(node *head)
{
    node *temp, *last = NULL;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        temp = (node *)malloc(sizeof(node));
        printf("Enter data and name: ");
        scanf("%d %s", &temp->data, temp->name);

        temp->next = NULL;

        if (head == NULL)
            head = last = temp;
        else
        {
            last->next = temp;
            last = temp;
        }
    }
    return head;
}

void display(node *head)
{
    node *p = head;
    while (p != NULL)
    {
        printf("%d %s -> ", p->data, p->name);
        p = p->next;
    }
    printf("NULL\n");
}

node *insert_before_key(node *head, int key, int value, char name[])
{
    if (head == NULL)
        return NULL;

    if (head->data == key)
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = value;
        strcpy(temp->name, name);
        temp->next = head;
        return temp;
    }

    node *p = head;

    while (p->next != NULL && p->next->data != key)
        p = p->next;

    if (p->next == NULL)
    {
        printf("Key not found!\n");
        return head;
    }

    node *temp = (node *)malloc(sizeof(node));
    temp->data = value;
    strcpy(temp->name, name);

    temp->next = p->next;
    p->next = temp;

    return head;
}
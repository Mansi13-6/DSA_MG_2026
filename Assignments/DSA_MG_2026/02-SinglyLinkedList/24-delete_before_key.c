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
node *delete_before_key(node *head, int key);

int main()
{
    node *head = NULL;
    int key;

    head = create(head);

    printf("\nOriginal List:\n");
    display(head);

    printf("Enter key to delete before: ");
    scanf("%d", &key);

    head = delete_before_key(head, key);

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

node *delete_before_key(node *head, int key)
{
    if (head == NULL || head->next == NULL)
    {
        printf("Deletion not possible!\n");
        return head;
    }

    if (head->next->data == key)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node *p = head;

    while (p->next->next != NULL && p->next->next->data != key)
        p = p->next;

    if (p->next->next == NULL)
    {
        printf("Key not found!\n");
        return head;
    }

    node *temp = p->next;
    p->next = temp->next;
    free(temp);

    return head;
}
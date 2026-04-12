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
node *insert(node *head, int data, char name[]);
node *delete_node(node *head, int key);
node *reverse(node *head);
void display(node *head);

int main()
{
    node *head = NULL;
    int choice, data, key;
    char name[50];

    do
    {
        printf("\n--- MENU ---");
        printf("\n1. Create");
        printf("\n2. Insert at End");
        printf("\n3. Delete by Key");
        printf("\n4. Reverse List");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = create(head);
            break;

        case 2:
            printf("Enter data and name: ");
            scanf("%d %s", &data, name);
            head = insert(head, data, name);
            break;

        case 3:
            printf("Enter key (data) to delete: ");
            scanf("%d", &key);
            head = delete_node(head, key);
            break;

        case 4:
            head = reverse(head);
            printf("List reversed successfully.\n");
            break;

        case 5:
            display(head);
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 6);

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

node *insert(node *head, int data, char name[])
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    strcpy(temp->name, name);
    temp->next = NULL;

    if (head == NULL)
        return temp;

    node *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}

node *delete_node(node *head, int key)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }

    if (head->data == key)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node *p = head;
    while (p->next != NULL && p->next->data != key)
        p = p->next;

    if (p->next == NULL)
    {
        printf("Key not found!\n");
        return head;
    }

    node *temp = p->next;
    p->next = temp->next;
    free(temp);

    return head;
}

node *reverse(node *head)
{
    node *prev = NULL, *curr = head, *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void display(node *head)
{
    node *p = head;

    if (p == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("\nLinked List:\n");
    while (p != NULL)
    {
        printf("%d %s -> ", p->data, p->name);
        p = p->next;
    }
    printf("NULL\n");
}
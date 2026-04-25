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
sl *insert(sl *head, int data, char name[]);
sl *delete_node(sl *head, int key);
sl *reverse(sl *head);
void display(sl *head);

int main()
{
    sl *head = NULL;
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

sl *insert(sl *head, int data, char name[])
{
    sl *temp = (sl*)malloc(sizeof(sl));
    temp->data = data;
    strcpy(temp->name, name);
    temp->next = NULL;

    if (head == NULL)
        return temp;

    sl *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}

sl *delete_node(sl *head, int key)
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
        p = p->next;

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

sl *reverse(sl *head)
{
    sl *prev = NULL, *curr = head, *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void display(sl *head)
{
    sl *p = head;

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
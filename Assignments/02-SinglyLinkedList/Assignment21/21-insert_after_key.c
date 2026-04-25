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
void display(sl *head);
sl *insert_after_key(sl *head, int key, int value, char name[]);

int main()
{
    sl *head = NULL;
    int key, value;
    char name[50];

    head = create(head);

    printf("\nOriginal List:\n");
    display(head);

    printf("Enter key, data and name to insert after: ");
    scanf("%d %d %s", &key, &value, name);

    head = insert_after_key(head, key, value, name);

    printf("\nUpdated List:\n");
    display(head);

    return 0;
}

sl* create(sl *head) 
{
    sl *temp, *last = NULL;
    int ch;

    do
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

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &ch);

    } while(ch != 0);

    return head;
}

void display(sl *head)
{
    sl *p = head;
    while (p != NULL)
    {
        printf("%d %s -> ", p->data, p->name);
        p = p->next;
    }
    printf("NULL\n");
}

sl *insert_after_key(sl *head, int key, int value, char name[])
{
    sl *p = head;

    while (p != NULL && p->data != key)
        p = p->next;

    if (p == NULL)
    {
        printf("Key not found!\n");
        return head;
    }

    sl *temp = (sl*)malloc(sizeof(sl));
    temp->data = value;
    strcpy(temp->name, name);

    temp->next = p->next;
    p->next = temp;

    return head;
}
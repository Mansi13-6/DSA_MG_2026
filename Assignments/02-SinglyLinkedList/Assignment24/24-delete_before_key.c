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
sl *delete_before_key(sl *head, int key);

int main()
{
    sl *head = NULL;
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

sl *delete_before_key(sl *head, int key)
{
    if (head == NULL || head->next == NULL)
    {
        printf("Deletion not possible!\n");
        return head;
    }

    if (head->next->data == key)
    {
        sl *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    sl *p = head;

    while (p->next->next != NULL && p->next->next->data != key)
        p = p->next;

    if (p->next->next == NULL)
    {
        printf("Key not found!\n");
        return head;
    }

    sl *temp = p->next;
    p->next = temp->next;
    free(temp);

    return head;
}
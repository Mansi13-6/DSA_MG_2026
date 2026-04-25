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
void display_reverse(sl *head);

int main()
{
    sl *head = NULL;

    head = create(head);

    printf("\nOriginal List:\n");
    display(head);

    printf("\nReverse Order:\n");
    display_reverse(head);

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

void display_reverse(sl *head)
{
    sl *p = head;
    sl *arr[100];  
    int top = 0;

    while (p != NULL)
    {
        arr[top++] = p;
        p = p->next;
    }

    for (int i = top - 1; i >= 0; i--)
    {
        printf("%d %s -> ", arr[i]->data, arr[i]->name);
    }

    printf("NULL\n");
}
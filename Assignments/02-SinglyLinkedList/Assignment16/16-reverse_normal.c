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
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
sl *append(sl *head1, sl *head2);

int main()
{
    sl *head1 = NULL, *head2 = NULL;

    printf("Create List 1:\n");
    head1 = create(head1);

    printf("\nCreate List 2:\n");
    head2 = create(head2);

    printf("\nList 1:\n");
    display(head1);

    printf("\nList 2:\n");
    display(head2);
    head1 = append(head1, head2);

    printf("\nAfter Appending List2 to List1:\n");
    display(head1);

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
sl *append(sl *head1, sl *head2)
{
    if (head1 == NULL)
        return head2;

    sl *p = head1;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = head2;

    return head1;
}
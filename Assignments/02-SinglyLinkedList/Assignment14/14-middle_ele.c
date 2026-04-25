#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} sl;

sl *create(sl *head);
void display(sl *head);
void find_middle(sl *head);

int main()
{
    sl *head = NULL;

    head = create(head);

    printf("\nLinked List:\n");
    display(head);

    find_middle(head);

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
        scanf("%d", &temp->data);

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
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void find_middle(sl *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    sl *slowptr = head;
    sl *fastptr = head;
    while (fastptr != NULL && fastptr->next != NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
    }

    printf("\nMiddle element = %d\n", slowptr->data);
}
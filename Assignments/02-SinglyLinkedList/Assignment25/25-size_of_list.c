#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLL
{
    int data;
    struct singlyLL *next;
} sl;

sl *create(sl *head);
void display(sl *head);
int count_nodes(sl *head);

int main()
{
    sl *head = NULL;
    int count;

    head = create(head);

    printf("\nLinked List:\n");
    display(head);

    count = count_nodes(head);

    printf("\nNumber of nodes in the list = %d\n", count);

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

int count_nodes(sl *head)
{
    int count = 0;
    sl *p = head;

    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}
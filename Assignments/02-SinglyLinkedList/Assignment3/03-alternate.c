#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLL
{
    int data;
    char name[20];  
    struct singlyLL *next;
}sl;

sl* create(sl *head);
void displayAlternate(sl *head);

int main()
{
    sl *head = NULL;
    head = create(head);
    displayAlternate(head);
    return 0;
}

sl* create(sl *head) 
{
    sl *temp, *last = NULL;
    int i, n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
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
    }
    return head;
}

void displayAlternate(sl *head)
{
    sl *p = head;
    printf("\nAlternate nodes are:\n");
    while(p != NULL)
    {
        printf("Data: %d, Name: %s\n", p->data, p->name);
        if(p->next != NULL)
            p = p->next->next;
        else
            break;
    }
}
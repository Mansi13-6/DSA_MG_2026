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
    int ch;
    do
    {
        temp = (sl*)malloc(sizeof(sl));

        if(temp == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        printf("Enter data and name: ");
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
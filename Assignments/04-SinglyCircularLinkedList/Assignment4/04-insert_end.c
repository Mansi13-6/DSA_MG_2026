#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}csll;

csll* create_list(int n);
csll* insert_at_end(csll *head,int data);
void display(csll *head);

csll* create_list(int n)
{
    csll *head = NULL,*temp = NULL,*nw;
    int data,i = 0;

    do
    {
        printf("Enter data: ");
        scanf("%d",&data);

        nw = (csll*)malloc(sizeof(csll));

        nw->data = data;
        nw->next = NULL;

        if(head == NULL)
        {
            head = temp = nw;
            nw->next = head;
        }
        else
        {
            temp->next = nw;
            temp = nw;
            temp->next = head;
        }

        i++;

    }while(i < n);

    return head;
}

csll* insert_at_end(csll *head,int data)
{
    csll *nw,*temp = head;

    nw = (csll*)malloc(sizeof(csll));

    nw->data = data;

    while(temp->next != head)
        temp = temp->next;

    temp->next = nw;
    nw->next = head;

    return head;
}

void display(csll *head)
{
    csll *temp = head;

    do
    {
        printf("%d -> ",temp->data);
        temp = temp->next;

    }while(temp != head);

    printf("HEAD\n");
}

int main()
{
    csll *head;
    int n,data;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    head = create_list(n);

    printf("Enter data: ");
    scanf("%d",&data);

    head = insert_at_end(head,data);

    display(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}dl;

dl* sorted_create(dl *head,int data);
void display(dl *head);

dl* sorted_create(dl *head,int data)
{
    dl *nw,*temp;

    nw = (dl*)malloc(sizeof(dl));

    nw->data = data;
    nw->next = NULL;
    nw->prev = NULL;

    if(head == NULL)
        return nw;

    if(data < head->data)
    {
        nw->next = head;
        head->prev = nw;

        return nw;
    }

    temp = head;

    while(temp->next != NULL && temp->next->data < data)
        temp = temp->next;

    nw->next = temp->next;

    if(temp->next != NULL)
        temp->next->prev = nw;

    temp->next = nw;
    nw->prev = temp;

    return head;
}

void display(dl *head)
{
    do
    {
        printf("%d <-> ", head->data);
        head = head->next;

    }while(head != NULL);

    printf("NULL\n");
}

int main()
{
    dl *head = NULL;
    int n,data,i = 0;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    do
    {
        printf("Enter data: ");
        scanf("%d",&data);

        head = sorted_create(head,data);

        i++;

    }while(i < n);

    display(head);

    return 0;
}
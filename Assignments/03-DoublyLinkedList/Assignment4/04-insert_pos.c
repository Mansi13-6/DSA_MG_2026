#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}dl;

dl* create_list(int n);
dl* insert_at_position(dl *head,int data,int pos);
void display(dl *head);

dl* create_list(int n)
{
    dl *head = NULL,*temp = NULL,*nw;
    int data,i = 0;

    do
    {
        printf("Enter data: ");
        scanf("%d",&data);

        nw = (dl*)malloc(sizeof(dl));

        nw->data = data;
        nw->next = NULL;
        nw->prev = NULL;

        if(head == NULL)
            head = temp = nw;
        else
        {
            temp->next = nw;
            nw->prev = temp;
            temp = nw;
        }

        i++;

    }while(i < n);

    return head;
}

dl* insert_at_position(dl *head,int data,int pos)
{
    dl *nw,*temp = head;
    int i = 1;

    nw = (dl*)malloc(sizeof(dl));

    nw->data = data;

    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }

    nw->next = temp->next;
    nw->prev = temp;

    temp->next->prev = nw;
    temp->next = nw;

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
    dl *head;
    int n,data,pos;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    head = create_list(n);

    printf("Enter data: ");
    scanf("%d",&data);

    printf("Enter position: ");
    scanf("%d",&pos);

    head = insert_at_position(head,data,pos);

    display(head);

    return 0;
}
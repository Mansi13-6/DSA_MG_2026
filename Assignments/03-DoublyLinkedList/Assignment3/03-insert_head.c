#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}dl;

dl* create_list(int n);
dl* insert_at_start(dl *head,int data);
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

dl* insert_at_start(dl *head,int data)
{
    dl *nw = (dl*)malloc(sizeof(dl));

    nw->data = data;
    nw->prev = NULL;
    nw->next = head;

    head->prev = nw;

    return nw;
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
    int n,data;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    head = create_list(n);

    printf("Enter data to insert: ");
    scanf("%d",&data);

    head = insert_at_start(head,data);

    display(head);

    return 0;
}
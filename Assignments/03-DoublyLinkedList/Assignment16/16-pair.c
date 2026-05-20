#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}dl;

dl* create_list(int n);
void rearrange(dl *head);
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

void rearrange(dl *head)
{
    int t;

    while(head != NULL && head->next != NULL)
    {
        if(head->data > head->next->data)
        {
            t = head->data;
            head->data = head->next->data;
            head->next->data = t;
        }

        head = head->next->next;
    }
}

void display(dl *head)
{
    do
    {
        printf("%d <-> ",head->data);
        head = head->next;

    }while(head != NULL);

    printf("NULL\n");
}

int main()
{
    dl *head;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    head = create_list(n);

    rearrange(head);

    display(head);

    return 0;
}
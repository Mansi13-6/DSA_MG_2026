#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}dl;

dl* create_list(int n);
void display_reverse(dl *head);

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

void display_reverse(dl *head)
{
    dl *temp = head;

    while(temp->next)
        temp = temp->next;

    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;

    }while(temp != NULL);

    printf("NULL\n");
}

int main()
{
    dl *head;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    head = create_list(n);

    display_reverse(head);

    return 0;
}
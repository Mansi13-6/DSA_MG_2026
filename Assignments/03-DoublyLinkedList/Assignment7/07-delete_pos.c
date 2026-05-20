#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}dl;

dl* create_list(int n);
dl* delete_at_position(dl *head,int pos);
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

dl* delete_at_position(dl *head,int pos)
{
    dl *temp = head;
    int i = 1;

    while(i < pos)
    {
        temp = temp->next;
        i++;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);

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
    int n,pos;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    head = create_list(n);

    printf("Enter position to delete: ");
    scanf("%d",&pos);

    head = delete_at_position(head,pos);

    display(head);

    return 0;
}
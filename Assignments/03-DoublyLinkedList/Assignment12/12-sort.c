#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}dl;

dl* create_list(int n);
void sort_list(dl *head);
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

void sort_list(dl *head)
{
    dl *temp1,*temp2;
    int t;

    for(temp1 = head; temp1 != NULL; temp1 = temp1->next)
    {
        for(temp2 = temp1->next; temp2 != NULL; temp2 = temp2->next)
        {
            if(temp1->data > temp2->data)
            {
                t = temp1->data;
                temp1->data = temp2->data;
                temp2->data = t;
            }
        }
    }
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
    int n;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    head = create_list(n);

    sort_list(head);

    display(head);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}dl;

dl* create_list(int n);
void sort_list(dl *head);
dl* merge(dl *head1,dl *head2);
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

dl* merge(dl *head1,dl *head2)
{
    dl *temp = head1;

    while(temp->next)
        temp = temp->next;

    temp->next = head2;
    head2->prev = temp;

    return head1;
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
    dl *head1,*head2,*head3;
    int n1,n2;

    printf("Enter nodes in list1: ");
    scanf("%d",&n1);

    head1 = create_list(n1);

    printf("Enter nodes in list2: ");
    scanf("%d",&n2);

    head2 = create_list(n2);

    sort_list(head1);
    sort_list(head2);

    head3 = merge(head1,head2);

    display(head3);

    return 0;
}
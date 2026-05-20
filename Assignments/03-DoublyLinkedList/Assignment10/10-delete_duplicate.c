#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}dl;

dl* create_list(int n);
dl* delete_duplicates(dl *head);
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

dl* delete_duplicates(dl *head)
{
    dl *temp1,*temp2,*dup;

    temp1 = head;

    while(temp1 != NULL)
    {
        temp2 = temp1->next;

        while(temp2 != NULL)
        {
            if(temp1->data == temp2->data)
            {
                dup = temp2;

                temp2->prev->next = temp2->next;

                if(temp2->next != NULL)
                    temp2->next->prev = temp2->prev;

                temp2 = temp2->next;

                free(dup);
            }
            else
                temp2 = temp2->next;
        }

        temp1 = temp1->next;
    }

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
    int n;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    head = create_list(n);

    head = delete_duplicates(head);

    display(head);

    return 0;
}
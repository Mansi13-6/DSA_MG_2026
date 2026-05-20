#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    char name[20];
    struct node *next,*prev;
}dl;

dl* create_list();
dl* delete_after_key(dl *head,int key);
void display(dl *head);

dl* create_list()
{
    dl *head = NULL,*temp = NULL,*nw;
    int i = 0;

    do
    {
        nw = (dl*)malloc(sizeof(dl));

        printf("Enter data and name: ");
        scanf("%d%s",&nw->data,nw->name);

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

    }while(i < 4);

    return head;
}

dl* delete_after_key(dl *head,int key)
{
    dl *temp = head,*del;

    while(temp != NULL && temp->data != key)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL)
    {
        printf("Deletion not possible\n");
        return head;
    }

    del = temp->next;

    temp->next = del->next;

    if(del->next != NULL)
        del->next->prev = temp;

    free(del);

    return head;
}

void display(dl *head)
{
    do
    {
        printf("|_%d_|_%s_| <-> ",head->data,head->name);

        head = head->next;

    }while(head != NULL);

    printf("NULL\n");
}

int main()
{
    dl *head;
    int key;

    head = create_list();

    printf("Enter key: ");
    scanf("%d",&key);

    head = delete_after_key(head,key);

    display(head);

    return 0;
}
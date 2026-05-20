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
dl* insert_after_key(dl *head,int key,int data,char name[]);
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

dl* insert_after_key(dl *head,int key,int data,char name[])
{
    dl *temp = head,*nw;

    while(temp->data != key)
        temp = temp->next;

    nw = (dl*)malloc(sizeof(dl));

    nw->data = data;
    strcpy(nw->name,name);

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
        printf("|_%d_|_%s_| <-> ",head->data,head->name);

        head = head->next;

    }while(head != NULL);

    printf("NULL\n");
}

int main()
{
    dl *head;
    int key,data;
    char name[20];

    head = create_list();

    printf("Enter key: ");
    scanf("%d",&key);

    printf("Enter data and name: ");
    scanf("%d%s",&data,name);

    head = insert_after_key(head,key,data,name);

    display(head);

    return 0;
}
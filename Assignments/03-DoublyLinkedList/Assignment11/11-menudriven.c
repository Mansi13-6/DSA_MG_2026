#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}dl;

dl *head = NULL;

void insert(int data);
void delete_start();
void display();
void reverse();

void insert(int data)
{
    dl *nw,*temp;

    nw = (dl*)malloc(sizeof(dl));

    nw->data = data;
    nw->next = NULL;
    nw->prev = NULL;

    if(head == NULL)
        head = nw;
    else
    {
        temp = head;

        while(temp->next)
            temp = temp->next;

        temp->next = nw;
        nw->prev = temp;
    }
}

void delete_start()
{
    dl *temp = head;

    head = head->next;
    head->prev = NULL;

    free(temp);
}

void display()
{
    dl *temp = head;

    do
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;

    }while(temp != NULL);

    printf("NULL\n");
}

void reverse()
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
    int ch,data;

    do
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Reverse");
        printf("\n5.Exit");

        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);

                insert(data);
                break;

            case 2:
                delete_start();
                break;

            case 3:
                display();
                break;

            case 4:
                reverse();
                break;
        }

    }while(ch != 5);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

typedef struct Node node;

node* createNode(int);
void insertEnd(node**, int);
void display(node*);
node* mergeSortedList(node*, node*);
node* freelist(node*);

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    node* merged = NULL;

    // First sorted list
    insertEnd(&head1, 1);
    insertEnd(&head1, 4);
    insertEnd(&head1, 7);
    insertEnd(&head1, 10);

    // Second sorted list
    insertEnd(&head2, 2);
    insertEnd(&head2, 3);
    insertEnd(&head2, 8);
    insertEnd(&head2, 9);

    printf("First List:\n");
    display(head1);

    printf("\nSecond List:\n");
    display(head2);

    merged = mergeSortedList(head1, head2);

    printf("\nMerged List:\n");
    display(merged);

    head1 = freelist(head1);
    head2 = freelist(head2);
    merged = freelist(merged);

    return 0;
}

node* createNode(int value)
{
    node* temp = (node*)malloc(sizeof(node));

    temp->data = value;
    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

void insertEnd(node** head, int value)
{
    node* temp = createNode(value);

    if(*head == NULL)
    {
        *head = temp;
        return;
    }

    node* p = *head;

    while(p->next != NULL)
    {
        p = p->next;
    }

    p->next = temp;
    temp->prev = p;
}

void display(node* head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

node* mergeSortedList(node* head1, node* head2)
{
    node* merge = NULL;
    node* p1 = head1;
    node* p2 = head2;

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->data <= p2->data)
        {
            insertEnd(&merge, p1->data);
            p1 = p1->next;
        }
        else
        {
            insertEnd(&merge, p2->data);
            p2 = p2->next;
        }
    }

    while(p1 != NULL)
    {
        insertEnd(&merge, p1->data);
        p1 = p1->next;
    }

    while(p2 != NULL)
    {
        insertEnd(&merge, p2->data);
        p2 = p2->next;
    }

    return merge;
}

node* freelist(node* head)
{
    node* temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return NULL;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node* create(node *head);
void display(node *head);
void sort(node *head);

int main()
{
    node *start = NULL;
    start = create(start);
    display(start);
    sort(start);
    printf("\nAfter sorting:\n");
    display(start);
    return 0;
}

node* create(node *head)
{
    node *temp, *last = NULL;
    int i;
    for(i = 0; i < 3; i++)
    {
        temp = (node*)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d", &temp->data);
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
    return head;
}

void display(node *p)
{
    if(p == NULL){
        printf("List is not created");
        return;
    }
    while(p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
}

void sort(node *head)
{
    node *i, *j;
    int temp;

    for(i = head; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
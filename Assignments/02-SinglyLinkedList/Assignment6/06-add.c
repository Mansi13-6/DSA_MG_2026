#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct singlyLL
{
    int data;
    char name[50];
    struct singlyLL *next;
}sl;

sl *create(sl *head);
void add(sl *head);
void display(sl *head);

int main()
{
    sl *head = NULL;
    head = create(head);

    printf("\nOriginal List:\n");
    display(head);
    add(head);
    printf("\nAfter Adding New Nodes:\n");
    display(head);

    return 0;
}
    sl* create(sl *head) 
    {
        sl *temp, *last = NULL;
        int i;
        for(i = 0; i < 5; i++)
        {
            temp = (sl*)malloc(sizeof(sl));
            printf("Enter the data and name: ");
            scanf("%d %s", &temp->data, temp->name);
            temp->next = NULL;
            if(head == NULL)
            {
                head = temp;
                last = temp;
            } 
            else 
            {
                last->next = temp;
                last = temp;
            }
        }
        return head;
    }

    void display(sl *head)
    {
        sl *p = head;
        printf("\nLinked List:\n");
        while(p != NULL)
        {
            printf("%d %s -> ", p->data, p->name);
            p = p->next;
        }
        printf("NULL\n");
    }


void add(sl *head)
{
    if(head == NULL || head->next == NULL)
        return;

    sl *p = head;
    sl *q;
    sl *new_node;

    while(p != NULL && p->next != NULL)
    {
        q = p->next;

        new_node = (sl*)malloc(sizeof(sl));
        if(new_node == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        new_node->data = p->data + q->data;

        strcpy(new_node->name, p->name);
        strcat(new_node->name, q->name);

        new_node->next = q->next;
        q->next = new_node;

        p = new_node->next;
    }
}
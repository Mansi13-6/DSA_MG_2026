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
void swap(sl *head);
void display(sl *head);

int main()
{
    sl *head = NULL;
    head = create(head);
    swap(head);
    display(head);
    return 0;
}

sl* create(sl *head) 
{
    sl *temp, *last = NULL;
    int i, n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        temp = (sl*)malloc(sizeof(sl));

        if(temp == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

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

void swap(sl *head)
{
    if(head == NULL || head->next == NULL){
        return;
    }
    sl *p = head;
    sl *q;
    while(p != NULL && p->next != NULL){
        q = p->next;
        int temp_data = p->data;
        p->data = q->data;
        q->data = temp_data;
        
        char temp_name[50];
        strcpy(temp_name, p->name);
        strcpy(p->name, q->name);
        strcpy(q->name, temp_name);

        p = q->next;
    }
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

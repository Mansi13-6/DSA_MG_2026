#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct singlyLL
{
    int no;
    char name[10];
    struct singlyLL *next;
} sl;

sl* create(sl *head);
void display(sl *head);
sl* findMiddle(sl *head);

int main()
{
    sl *start = NULL;

    start = create(start);

    printf("\nLinked List:\n");
    display(start);

    sl *mid = findMiddle(start);

    if(mid != NULL)
    {
        printf("\nMiddle Node: %d %s\n", mid->no, mid->name);
    }

    return 0;
}

sl* create(sl *head) 
{
    sl *temp, *last = NULL;
    int i;

    for(i = 0; i < 5; i++)  
    {
        temp = (sl*)malloc(sizeof(sl));
        printf("Enter no and name: ");
        scanf("%d %s", &temp->no, temp->name);
        temp->next = NULL;

        if(head == NULL){
            head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }
    return head;
}

void display(sl *head)
{
    sl *p = head;
    while(p != NULL){
        printf("%d %s -> ", p->no, p->name);
        p = p->next;
    }
    printf("NULL\n");
}


sl* findMiddle(sl *head)
{
    sl *slow = head;
    sl *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}dl;

dl* create_list(int n);
void detect_cycle(dl *head);

dl* create_list(int n)
{
    dl *head = NULL,*temp = NULL,*nw,*last;
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

        last = nw;

        i++;

    }while(i < n);

    last->next = head;

    return head;
}

void detect_cycle(dl *head)
{
    dl *slow = head,*fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            printf("Cycle Detected\n");
            return;
        }
    }

    printf("Cycle Not Detected\n");
}

int main()
{
    dl *head;
    int n;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    head = create_list(n);

    detect_cycle(head);

    return 0;
}
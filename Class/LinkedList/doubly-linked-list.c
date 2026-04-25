#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next, *prev;
} dl;

dl* create_list(int n);
void display(dl *head);
void display_reverse_recursive(dl *head);
void display_reverse_iterative(dl *head);
dl* insert_at_start(dl *head, int data);
dl* delete_at_start(dl *head);
dl* delete_at_end(dl *head);
void search(dl *head, int key);
void free_list(dl *head);

dl* create_list(int n) 
{
    dl *head = NULL, *temp = NULL, *nw;
    int data, i;

    for(i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &data);

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
    }
    return head;
}
void display(dl *head) 
{
    printf("List: ");
    while(head) 
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void display_reverse_recursive(dl *head) {
    if(head == NULL)
        return;

    display_reverse_recursive(head->next);
    printf("%d <-> ", head->data);
}

void display_reverse_iterative(dl *head) 
{
    if(head == NULL) 
    {
        printf("NULL\n");
        return;
    }
    dl *temp = head;
    while(temp->next)
        temp = temp->next;
    while(temp) 
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

dl* reverse_linking(dl *head)
{
    dl *temp = NULL;
    dl *current = head;

    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        
        current = current->prev;
    }                           
    if(temp != NULL)
        head = temp->prev;

    return head;
}

dl* max_node(dl* head)
{
    if(head == NULL)
        return NULL;

    dl* max = head;
    while(head != NULL)
    {
        if(head->data > max->data)
        {
            max = head;
        }
        head = head->next;
    }
    return max;
}

dl* min_node(dl* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    dl* min=head;
    while(head != NULL)
    {
        if(head->data < min->data)
        {
            min=head;
        }
        head=head->next;
    }
    return min;
}

dl* insert_at_start(dl *head, int data) 
{
    dl *nw = (dl*)malloc(sizeof(dl));

    nw->data = data;
    nw->prev = NULL;
    nw->next = head;

    if(head)
        head->prev = nw;

    return nw;
}

dl* delete_at_start(dl *head) 
{
    if(head == NULL)
        return NULL;

    dl *temp = head;
    head = head->next;

    if(head)
        head->prev = NULL;

    free(temp);
    return head;
}
dl* delete_at_end(dl *head) 
{
    if(head == NULL)
        return NULL;

    dl *temp = head;

    while(temp->next)
        temp = temp->next;

    if(temp->prev)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
    return head;
}

void search(dl *head, int key) 
{
    int pos = 1;

    while(head) 
    {
        if(head->data == key) 
        {
            printf("Found at position %d\n", pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Not found\n");
}

void free_list(dl *head) 
{
    dl *temp;
    while(head) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    dl *head = NULL;
    int n, data, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    head = create_list(n);
    display(head);

    printf("\nEnter data to insert at start: ");
    scanf("%d", &data);
    head = insert_at_start(head, data);
    display(head);

    printf("\nReverse (Recursion): ");
    if(head == NULL)
        printf("NULL\n");
    else {
        display_reverse_recursive(head);
        printf("NULL\n");
    }

    printf("\nReverse (Using iteration): ");
    display_reverse_iterative(head);

    printf("\nAfter reversing linking:\n");
    head = reverse_linking(head);
    display(head);
    dl *max, *min;

    max = max_node(head);
    min = min_node(head);

    if(max != NULL)
        printf("\nMax value = %d\n", max->data);
    else
        printf("\nList is empty\n");

    if(min != NULL)
        printf("Min value = %d\n", min->data);

    head = delete_at_start(head);
    printf("\nAfter delete at start:\n");
    display(head);

    head = delete_at_end(head);
    printf("\nAfter delete at end:\n");
    display(head);

    printf("\nEnter data to search: ");
    scanf("%d", &key);
    search(head, key);

    free_list(head);
    head = NULL;

    printf("\nDestroyed\n");
    display(head); 

    return 0;
}
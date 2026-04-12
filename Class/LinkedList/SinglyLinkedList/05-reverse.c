#include <stdio.h>
#include <stdlib.h>

typedef struct singlyLL{
    int data;
    struct node *next;
}sl;

sl *reverse(sl *head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    sl *new = reverse(head->next);
    head->next->next = head;
    head->next=NULL;
    return new;
}

void display(sl *head){
    sl *p = head;
    while(p != NULL){
        printf("%d %s -> ", p->no);
        p = p->next;
    }
    printf("NULL\n");
}


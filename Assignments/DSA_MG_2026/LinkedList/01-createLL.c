#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud{
    int no;
    char name[10];
    struct stud *next;
} S;

S* create(S *head);
void display(S *head);
void swap(S *head);
void add(S *head);
void search(S *head, int key);

int main(){
    S *start = NULL;
    int key;
    start = create(start);
    display(start);
    swap(start);
    printf("\nAfter swap:\n");
    display(start);
    add(start);
    printf("\nAfter add:\n");
    display(start);
    printf("\nEnter number to search: ");
    scanf("%d", &key);
    search(start, key);
    return 0;
}
S* create(S *head){
    S *temp, *last = NULL;
    int i;
    for(i = 0; i < 3; i++){
        temp = (S*)malloc(sizeof(S));
        printf("Enter the no and name: ");
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

void swap(S *head){
    if(head == NULL || head->next == NULL){
        return;
    }
    S *p = head;
    S *q;
    while(p != NULL && p->next != NULL){
        q = p->next;
        int tempno = p->no;
        char tempname[10];
        p->no = q->no;
        q->no = tempno;
        strcpy(tempname, p->name);
        strcpy(p->name, q->name);
        strcpy(q->name, tempname);
        p = q->next;
    }
}
void add(S *head){
    if(head == NULL || head->next == NULL){
        return;
    }
    S *p = head;
    S *q;
    S *new;
    for(  ;p != NULL && p->next != NULL; p = new->next){
        q = p->next;
        new = (S*)malloc(sizeof(S));
        if(new == NULL){
            printf("Memory allocation failed");
            return;
        }
        new->no = p->no + q->no;
        strcpy(new->name, p->name);
        strcat(new->name, q->name);
        new->next = q->next;
        q->next = new;
    }
}
void search(S *head, int key){
    S *p = head;
    int position = 1;
    while(p != NULL){
        if(p->no == key){
            printf("Found at position %d: %d %s\n", position, p->no, p->name);
            return;
        }
        p = p->next;
        position++;
    }
    printf("Element not found");
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct singlyLL{
    int no;
    char name[20];  
    struct singlyLL *next;
}sl;

sl *insert_at_head(sl *head, int data, char name[]){
    sl *new = (sl*) malloc(sizeof(sl));
    new->no = data;
    strcpy(new->name, name);

    if(head==NULL){
        new->next=NULL;
    }else{
        new->next=head;
    }
    return new;
}

sl *insert_at_end(sl *head, int data, char name[]){
    sl *new = (sl*) malloc(sizeof(sl));
    new->no = data;
    strcpy(new->name, name);
    new->next = NULL;
    if(head==NULL){
        return new;
    }
    sl *p;
    for(p=head; p->next!=NULL; p=p->next);  
    p->next=new;
    return head;
}

sl *insert_at_pos(sl *head, int pos, int data, char name[]){
    sl *new = (sl*) malloc(sizeof(sl));
    new->no = data;
    strcpy(new->name, name);

    if(pos==1){
        new->next=head;
        return new;
    }

    sl *p=head;
    for(int i=1; i<pos-1 && p!=NULL; i++){
        p=p->next;
    }

    if(p==NULL){
        printf("Invalid position\n");
        return head;
    }

    new->next=p->next;
    p->next=new;
    return head;
}

void display(sl *head){
    sl *p=head;
    while(p!=NULL){
        printf("%d %s -> ", p->no, p->name);
        p=p->next;
    }
    printf("NULL\n");
}

int main(){
    sl *head = NULL; 
    int data, pos;
    char name[20];

    printf("Enter 4 nodes (data name):\n");
    for(int i=0; i<4; i++){
        scanf("%d %s", &data, name);
        head = insert_at_end(head, data, name);
    }

    printf("\nInitial List:\n");
    display(head);

    printf("\nEnter ONE node (data name): ");
    scanf("%d %s", &data, name);

    head = insert_at_head(head, data, name);
    printf("\nAfter insertion at head:\n");
    display(head);

    head = insert_at_end(head, data, name);
    printf("\nAfter insertion at end:\n");
    display(head);

    printf("\nEnter position: ");
    scanf("%d", &pos);

    head = insert_at_pos(head, pos, data, name);
    printf("\nAfter insertion at position:\n");
    display(head);

    return 0;
}
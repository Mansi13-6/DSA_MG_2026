#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct singlyLL{
    int no;
    char name[20];  
    struct singlyLL *next;
}sl;

sl *delete_at_head(sl *head){
    if(head==NULL){
        return head;
    }
    sl *p=head;
    head=head->next;
    free(p);
    return head;
}

sl *delete_at_end(sl *head){
    if(head==NULL){
        return head;
    }
    sl *p=head;
    if(p->next==NULL){
        free(p);
        return NULL;
    }
    while(p->next->next!=NULL){
        p=p->next;
    }
    free(p->next);
    p->next=NULL;

    return head;
}

sl *delete_at_pos(sl *head, int pos){
    if(head==NULL){
        return head;
    }
    sl *p=head;
    if(pos==1){
        head=head->next;
        free(p);
        return head;
    }
    for(int i=1; i<pos-1 && p->next!=NULL; i++){
        p=p->next;
    }
    if(p->next==NULL){
        printf("Invalid position\n");
        return head;
    }
    sl *temp = p->next;
    p->next = temp->next;
    free(temp);

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
    printf("\nOriginal List:\n");
    display(head);

    head = delete_at_head(head);
    printf("\nAfter delete at head:\n");
    display(head);

    head = delete_at_end(head);
    printf("\nAfter delete at end:\n");
    display(head);

    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    head = delete_at_pos(head, pos);
    printf("\nAfter delete at position:\n");
    display(head);

    return 0;
}
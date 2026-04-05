#include <stdio.h>
#include <stdlib.h>

struct student 
{
    char name[50];
    int rollno;
    int std;
    char div;
    struct student *next;
};

int main() 
{
    struct student *head = NULL, *temp, *new_node;
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) 
    {
        new_node = (struct student*)malloc(sizeof(struct student));

        printf("\nEnter Name: ");
        scanf("%s", new_node->name);

        printf("Enter Roll No: ");
        scanf("%d", &new_node->rollno);

        printf("Enter Std: ");
        scanf("%d", &new_node->std);

        printf("Enter Division: ");
        scanf(" %c", &new_node->div);

        new_node->next = NULL;
        if(head == NULL) 
        {
            head = new_node;
            temp = new_node;
        } 
        else 
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    temp = head;
    printf("\nStudent List:\n");
    while(temp != NULL) 
    {
        printf("\nName: %s", temp->name);
        printf("\nRoll No: %d", temp->rollno);
        printf("\nStd: %d", temp->std);
        printf("\nDiv: %c\n", temp->div);
        temp = temp->next;
    }

    return 0;
}
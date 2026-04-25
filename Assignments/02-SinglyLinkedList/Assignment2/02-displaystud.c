#include <stdio.h>
#include <stdlib.h>

typedef struct student 
{
    char name[50];
    int rollno;
    int std;
    char div;
    struct student *next;
} s;

s* create(s*);
void display(s*);
void freeList(s*);

int main()
{
    s* head = NULL;
    head = create(head);
    display(head);
    freeList(head);
    return 0;
}

s* create(s* head)
{
    s *newNode = NULL, *last = NULL;
    int ch;

    do
    {
        newNode = (s*)malloc(sizeof(s));

        if(newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        printf("Enter student name: ");
        scanf(" %[^\n]", newNode->name);   // read full name

        printf("Enter student roll no: ");
        scanf("%d", &newNode->rollno);

        printf("Enter student std: ");
        scanf("%d", &newNode->std);

        printf("Enter student div: ");
        scanf(" %c", &newNode->div);  

        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &ch);

    } while(ch != 0);

    return head;
}

void display(s* temp)
{
    printf("\n---- DISPLAYING LIST OF STUDENTS ----\n");

    while(temp != NULL)
    {
        printf("\nName      : %s\n", temp->name);
        printf("Roll No   : %d\n", temp->rollno);
        printf("Standard  : %d\n", temp->std);
        printf("Division  : %c\n", temp->div);

        temp = temp->next;
    }
}

void freeList(s* head)
{
    s* temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
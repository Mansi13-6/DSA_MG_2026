#include <stdio.h>

struct student
{
    int rollno;
    char name[50];
    int std;
    char div;
};

int main()
{
    struct student *p;
    p = (struct student*)malloc(sizeof(struct student));
    
    printf("Enter roll no: ");
    scanf("%d", &p->rollno);
    printf("Enter name: ");
    scanf("%s", p->name);
    printf("Enter standard: ");
    scanf("%d", &p->std);
    printf("Enter division: ");
    scanf("%c", &p->div);

    printf("\nStudent Details:\n");
    printf("Roll Number: %d\n", p->rollno);
    printf("Name: %s\n", p->name);
    printf("Standard: %d\n", p->std);
    printf("Division: %c\n", p->div);
    return 0;
}
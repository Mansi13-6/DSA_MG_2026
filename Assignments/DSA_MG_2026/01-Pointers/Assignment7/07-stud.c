#include <stdio.h>

struct student
{
    int rollno;
    char name[50];
    float marks;
};

int main()
{
    struct student s;
    struct student *p;
    p=&s;
    printf("Enter roll no: ");
    scanf("%d", &p->rollno);
    printf("Enter name: ");
    scanf("%s", p->name);
    printf("Enter marks: ");
    scanf("%f", &p->marks);
    printf("\nStudent Details:\n");
    printf("Roll Number: %d\n", p->rollno);
    printf("Name: %s\n", p->name);
    printf("Marks: %.2f\n", p->marks);

    return 0;
}
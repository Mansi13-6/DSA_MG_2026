#include<stdio.h>
#include<stdlib.h>

struct student
{
    int roll;
    char name[20];
    float marks;
};

int main()
{
    struct student *s;

    s = (struct student*)malloc(sizeof(struct student));

    printf("Enter roll: ");
    scanf("%d",&s->roll);

    printf("Enter name: ");
    scanf("%s",s->name);

    printf("Enter marks: ");
    scanf("%f",&s->marks);

    printf("\nStudent Details:\n");
    printf("%d %s %.2f",s->roll,s->name,s->marks);

    free(s);

    return 0;
}
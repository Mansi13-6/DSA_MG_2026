#include<stdio.h>

struct student
{
    int roll;
    char name[20];
    float marks;
};

int main()
{
    struct student s = {1,"Mansi",85.5};
    printf("Roll: %d\n",s.roll);
    printf("Name: %s\n",s.name);
    printf("Marks: %.2f",s.marks);

    return 0;
}
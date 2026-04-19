#include<stdio.h>

struct employee
{
    int id;
    char name[20];
    float salary;
};

int main()
{
    struct employee e;
    printf("Enter id name salary: ");
    scanf("%d %s %f",&e.id,e.name,&e.salary);
    printf("Employee Details:\n");
    printf("%d %s %.2f",e.id,e.name,e.salary);

    return 0;
}
#include<stdio.h>

struct employee
{
    char company[20];
    int id;
    float salary;
    int exp;
};

struct person
{
    char name[20];
    int age;
    char dob[15];
    char bg[5];
    struct employee e;
};

int main()
{
    struct person p;

    printf("Enter name age dob bloodgroup: ");
    scanf("%s %d %s %s",p.name,&p.age,p.dob,p.bg);

    printf("Enter company id salary experience: ");
    scanf("%s %d %f %d",p.e.company,&p.e.id,&p.e.salary,&p.e.exp);

    printf("\nDetails:\n");
    printf("%s %d %s %s\n",p.name,p.age,p.dob,p.bg);
    printf("%s %d %.2f %d",p.e.company,p.e.id,p.e.salary,p.e.exp);

    return 0;
}

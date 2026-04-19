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
    int n,i;

    printf("Enter number of students: ");
    scanf("%d",&n);

    struct student *s;
    s = (struct student*)malloc(n*sizeof(struct student));

    for(i=0;i<n;i++)
    {
        printf("Enter roll name marks: ");
        scanf("%d %s %f",&s[i].roll,s[i].name,&s[i].marks);
    }

    printf("\nStudent Details:\n");
    for(i=0;i<n;i++)
    {
        printf("%d %s %.2f\n",s[i].roll,s[i].name,s[i].marks);
    }

    free(s);

    return 0;
}
#include<stdio.h>

struct student
{
    int roll;
    char name[20];
    float marks;
};

void search(struct student s[], int n, int key)
{
    int i,found=0;
    for(i=0;i<n;i++)
    {
        if(s[i].roll==key)
        {
            printf("Found: %d %s %.2f",s[i].roll,s[i].name,s[i].marks);
            found=1;
        }
    }
    if(found==0)
        printf("Not Found");
}

int main()
{
    int n,i,key;
    printf("Enter number of students: ");
    scanf("%d",&n);
    struct student s[n];

    for(i=0;i<n;i++)
    {
        printf("Enter roll name marks: ");
        scanf("%d %s %f",&s[i].roll,s[i].name,&s[i].marks);
    }

    printf("Enter roll to search: ");
    scanf("%d",&key);
    search(s,n,key);

    return 0;
}
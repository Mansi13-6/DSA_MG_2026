#include<stdio.h>

struct student
{
    char name[20];
    int roll;
    int marks[5];
    float per;
};

int main()
{
    int n,i,j;
    float max=0;
    int top=0;

    printf("Enter number of students: ");
    scanf("%d",&n);

    struct student s[n];

    for(i=0;i<n;i++)
    {
        printf("Enter name roll: ");
        scanf("%s %d",s[i].name,&s[i].roll);

        int sum=0;
        printf("Enter 5 marks: ");
        for(j=0;j<5;j++)
        {
            scanf("%d",&s[i].marks[j]);
            sum += s[i].marks[j];
        }

        s[i].per = sum/5.0;

        if(s[i].per > max)
        {
            max = s[i].per;
            top = i;
        }
    }

    printf("\nAll Students:\n");
    for(i=0;i<n;i++)
    {
        printf("%s %d %.2f\n",s[i].name,s[i].roll,s[i].per);
    }

    printf("\nTopper:\n");
    printf("%s %d %.2f",s[top].name,s[top].roll,s[top].per);

    return 0;
}
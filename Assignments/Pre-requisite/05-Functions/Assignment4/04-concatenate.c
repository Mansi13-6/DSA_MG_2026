#include<stdio.h>

void concat(char s1[], char s2[])
{
    int i=0,j=0;

    while(s1[i]!='\0')
        i++;

    while(s2[j]!='\0')
    {
        s1[i]=s2[j];
        i++;
        j++;
    }
    s1[i]='\0';
}

int main()
{
    char s1[100],s2[50];

    printf("Enter first string: ");
    scanf(" %[^\n]",s1);

    printf("Enter second string: ");
    scanf(" %[^\n]",s2);

    concat(s1,s2);

    printf("Result: %s",s1);

    return 0;
}
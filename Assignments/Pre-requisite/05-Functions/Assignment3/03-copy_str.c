#include<stdio.h>

void copyStr(char s1[], char s2[])
{
    int i=0;
    while(s1[i]!='\0')
    {
        s2[i]=s1[i];
        i++;
    }
    s2[i]='\0';
}

int main()
{
    char s1[50],s2[50];

    printf("Enter string: ");
    scanf(" %[^\n]",s1);

    copyStr(s1,s2);

    printf("Copied string: %s",s2);

    return 0;
}
#include<stdio.h>

void reverse(char str[])
{
    int i=0,j=0;
    char temp;

    while(str[j]!='\0')
        j++;
    j--;

    while(i<j)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        i++;
        j--;
    }
}

int main()
{
    char str[50];

    printf("Enter string: ");
    scanf(" %[^\n]",str);

    reverse(str);

    printf("Reversed: %s",str);

    return 0;
}
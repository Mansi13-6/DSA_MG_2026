#include<stdio.h>

int strLength(char str[])
{
    int i=0;
    while(str[i]!='\0')
        i++;
    return i;
}

int main()
{
    char str[50];

    printf("Enter string: ");
    scanf(" %[^\n]",str);

    int len = strLength(str);

    printf("Length = %d",len);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char *str;

    str = (char*)malloc(50*sizeof(char));

    printf("Enter text: ");
    scanf(" %[^\n]",str);

    printf("Text is: %s",str);

    free(str);

    return 0;
}
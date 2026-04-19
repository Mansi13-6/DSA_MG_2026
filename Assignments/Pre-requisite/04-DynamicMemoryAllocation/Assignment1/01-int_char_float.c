#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *a;
    char *ch;
    float *f;

    a = (int*)malloc(sizeof(int));
    ch = (char*)malloc(sizeof(char));
    f = (float*)malloc(sizeof(float));

    printf("Enter int value: ");
    scanf("%d",a);

    printf("Enter char value: ");
    scanf(" %c",ch);

    printf("Enter float value: ");
    scanf("%f",f);

    printf("Values are: %d %c %.2f",*a,*ch,*f);

    free(a);
    free(ch);
    free(f);

    return 0;
}
    #include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,sum=0;

    printf("Enter size: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));

    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
        sum += arr[i];
    }

    printf("\nSum = %d",sum);

    free(arr);

    return 0;
}
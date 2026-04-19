#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i;

    printf("Enter size: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));

    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int max=arr[0],curr=arr[0];

    for(i=1;i<n;i++)
    {
        if(curr+arr[i]>arr[i])
            curr=curr+arr[i];
        else
            curr=arr[i];

        if(curr>max)
            max=curr;
    }

    printf("Max Sum: %d",max);

    return 0;
}
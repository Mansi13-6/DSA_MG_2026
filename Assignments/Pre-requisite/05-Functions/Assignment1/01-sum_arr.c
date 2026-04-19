#include<stdio.h>

int sumArray(int arr[], int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
        sum += arr[i];
    return sum;
}

int main()
{
    int n,i;

    printf("Enter size: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int result = sumArray(arr,n);

    printf("Sum = %d",result);

    return 0;
}
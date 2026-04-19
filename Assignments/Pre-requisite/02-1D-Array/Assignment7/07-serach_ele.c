#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,key,flag=0;

    printf("Enter size: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));

    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter element to search: ");
    scanf("%d",&key);

    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
            flag=1;
    }

    if(flag==1)
        printf("Found");
    else
        printf("Not Found");

    return 0;
}
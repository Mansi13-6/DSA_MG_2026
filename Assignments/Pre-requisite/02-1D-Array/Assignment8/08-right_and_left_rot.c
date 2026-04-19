#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i,k,choice;

    printf("Enter size: ");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));

    printf("Enter elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter number of rotations: ");
    scanf("%d",&k);

    printf("1. Left Rotation\n2. Right Rotation\n");
    scanf("%d",&choice);

    if(choice==1)
    {
        for(int r=0;r<k;r++)
        {
            int first=arr[0];
            for(i=0;i<n-1;i++)
                arr[i]=arr[i+1];
            arr[n-1]=first;
        }
    }
    else if(choice==2)
    {
        for(int r=0;r<k;r++)
        {
            int last=arr[n-1];
            for(i=n-1;i>0;i--)
                arr[i]=arr[i-1];
            arr[0]=last;
        }
    }

    printf("Result: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
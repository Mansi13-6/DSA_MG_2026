#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n1,n2,i,j,temp;

    printf("Enter size of first array: ");
    scanf("%d",&n1);

    int *a = (int*)malloc(n1*sizeof(int));

    printf("Enter elements: ");
    for(i=0;i<n1;i++)
        scanf("%d",&a[i]);

    printf("Enter size of second array: ");
    scanf("%d",&n2);

    int *b = (int*)malloc(n2*sizeof(int));

    printf("Enter elements: ");
    for(i=0;i<n2;i++)
        scanf("%d",&b[i]);

    int n=n1+n2;
    int *c = (int*)malloc(n*sizeof(int));

    for(i=0;i<n1;i++)
        c[i]=a[i];

    for(i=0;i<n2;i++)
        c[i+n1]=b[i];

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(c[i]>c[j])
            {
                temp=c[i];
                c[i]=c[j];
                c[j]=temp;
            }
        }
    }

    for(i=0;i<n;i++)
        printf("%d ",c[i]);

    return 0;
}
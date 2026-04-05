#include <stdio.h>

int *sum_array(int *a, int *b, int n)
{
    static int result[10];
    int i;
    for(i=0; i<n; i++)
    {
        result[i]=*(a+i)+*(b+i);

    }
    return result;
}

int main()
{
    int arr1[5]={1, 2, 3, 4, 5};
    int arr2[5]={20, 30, 40, 50, 70};
    int *res;
    int i;
    res=sum_array(arr1, arr2, 5);
    printf("Sum of array:");
    for(i=0; i<5; i++)
    {
        printf("%d", *(res+i));
    }
    return 0;
}
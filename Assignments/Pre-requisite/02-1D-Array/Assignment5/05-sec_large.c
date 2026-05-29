#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, temp;
    int secondLargest;

    printf("Enter size: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter elements: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    secondLargest = arr[n - 1];

    for (i = n - 2; i >= 0; i--)
    {
        if (arr[i] != arr[n - 1])
        {
            secondLargest = arr[i];
            break;
        }
    }

    if (secondLargest == arr[n - 1])
    {
        printf("Second largest element not found");
    }
    else
    {
        printf("Second largest: %d", secondLargest);
    }

    free(arr);

    return 0;
}
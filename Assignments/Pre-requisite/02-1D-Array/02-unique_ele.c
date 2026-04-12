#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int n, i, j, value, isDuplicate;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);

        isDuplicate = 0;
        for (j = 0; j < i; j++)
        {
            if (arr[j] == value)
            {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate)
        {
            printf("Duplicate element! Enter again.\n");
            i--;  
        }
        else
        {
            arr[i] = value;
        }
    }
    printf("\nArray with unique elements:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    free(arr);

    return 0;
}
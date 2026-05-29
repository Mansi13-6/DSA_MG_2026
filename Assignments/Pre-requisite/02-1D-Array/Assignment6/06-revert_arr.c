#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, temp;

    printf("Enter size: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter elements: ");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    printf("Reversed array: ");

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);

    return 0;
}
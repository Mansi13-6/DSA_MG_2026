#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr, *visited;
    int n, i, j, count;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    visited = (int *)malloc(n * sizeof(int));
    if (arr == NULL || visited == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        visited[i] = 0; 
    }
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 1)
            continue;

        count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                visited[j] = 1;
            }
        }

        printf("Element %d occurs %d times\n", arr[i], count);
    }
    free(arr);
    free(visited);

    return 0;
}
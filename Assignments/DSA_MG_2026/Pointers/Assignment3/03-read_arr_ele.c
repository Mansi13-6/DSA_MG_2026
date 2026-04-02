#include <stdio.h>

int main() {
    int arr[5], i;
    int *ptr;
    printf("Enter 5 elements:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }
    ptr = arr;  
    printf("\nArray elements and their addresses:\n");
    for(i = 0; i < 5; i++) {
        printf("Element = %d, Address = %p\n", *(ptr + i), (ptr + i));
    }
    return 0;
}
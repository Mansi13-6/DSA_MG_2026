#include <stdio.h>
void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void rightRotate(int arr[], int n) {
    int temp = arr[n - 1];   

    for(int i = n - 2; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }
    arr[0] = temp; 
}
int main() {
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int n = 8;
    printf("Original Array:\n");
    display(arr, n);
    rightRotate(arr, n);
    printf("After Right Rotation:\n");
    display(arr, n);
    return 0;
}
#include <stdio.h>
void rightRotate(int arr[], int N){
    int i=N-2;
    int temp=arr[N-1];
    while(i>=0 && arr[i]>0){
        arr[i+1]=arr[i];
        i-=1;
    }
    arr[i+1]=temp;
}
int main(){
    int N=8;
    int arr[8]={-12, -10, -20, 30, 40, 50, 80, 76};
    rightRotate(arr, N);
    printf("After Right Rotation:\n");
    for(int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
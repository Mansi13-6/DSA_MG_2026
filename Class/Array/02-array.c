#include <stdio.h>
int main(void){
    int arr[8] = {10,20,30,40,50,60,70,80};
    int temp;
    temp = arr[7];  
    int i = 6;
    while(i >= 0){
        arr[i+1] = arr[i];
        i -= 1;
    }
    arr[0] = temp;  
    for(int i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
#include <stdio.h>
int main(void){
    int arr[8]={-15, -8, -2, 1, 5, 15, 30, 45};
    int i;
    int temp=arr[7];
    for(i=0; i<8; i++){
        if(arr[i]>=0){
            arr[i+1]=arr[i];
            i-=1;
        }
        arr[i]=temp;
    }
    for(i=0; i<8; i++){
        printf("%d", arr[i]);
    }
    return 0;
}
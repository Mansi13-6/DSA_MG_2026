#include <stdio.h>
void insertion_sort(int a[], int N);
void insert_at_sorting_pos(int a[], int N);
void display(int a[], int N, const char* msg);
int main(void){
    int a[6]={50, 30, 20, 15, 10, 40};

    display(a, 6, "Displaying  \'a\' before insertion_sort():");
    insertion_sort(a, 6);
    display(a, 6, "Displaying  \'a\' after insertion_sort():");

    return 0;
}
void insertion_sort(int a[], int N){
    int subarray_size;
    subarray_size=2;
    while(subarray_size <= N){
        insert_at_sorting_pos(a, subarray_size);
        subarray_size = subarray_size + 1;
    }
}
void insert_at_sorting_pos(int a[], int N){
    int tmp;
    int i;
    tmp = a[N-1];
    i = N-2;
    while(i >= 0 && a[i]>tmp){
        a[i+1]=a[i];
        i-=1;
    }
    a[i+1]=tmp;
}
void display(int a[], int N, const char* msg){
    if(msg!=NULL)
       puts(msg);

    int i;
    i=0;
    while(i<N){
        printf("a[%d]:%d\n", i, a[i]);
        i+=1;
    }   
}




















// #include <stdio.h>
// void sort(int arr[], int n){
//     int i, j, temp;
//     for(i=0; i<n-1; i++){
//         for (j=0; j<n-i-1; j++){
//             if(arr[j] > arr[j+1]){
//                 temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//             }
//         } 
//     }
// }
// int main(){
//     int arr[6]={50, 40, 10, 20, 80, 5};
//     int n=6;
//     sort(arr,n);
//     printf("Sorted array:\n");
//     for(int i=0; i<n; i++){
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }


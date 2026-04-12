#include <stdio.h>
void insert_at_sorting_pos(int a[], int N);
void display(int a[], int N, const char* msg);
int main(void){
    int a[6]={50, 30, 20, 15, 10, 40};
    display(a, 6, "Displaying  \'a\' before insert_at_sorting_pos():");
    insert_at_sorting_pos(a, 6);
    display(a, 6, "Displaying  \'a\' after insert_at_sorting_pos():");
    return 0;
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
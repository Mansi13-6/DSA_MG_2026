#include <stdio.h>
int main(){
    int a[5]={10, 80, 50, 20, 40};
    int b[5]={34, 76, 11, 34, 67};
    int i, temp;
    int *p1=a;
    int *p2=b;
    for(i=0; i<5; i++){
        temp=*(p1+i);
        *(p1+i)=*(p2+i);
        *(p2+i)=temp;
    }
    for(i=0; i<5; i++){
    printf("%d ", a[i]);
    }
    for(i=0; i<5; i++){
    printf("%d ", b[i]);
    }
    return 0;
}
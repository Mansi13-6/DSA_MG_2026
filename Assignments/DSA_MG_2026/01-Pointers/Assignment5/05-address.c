#include <stdio.h>

int main()
{
    int a=9;
    float=6.6;
    char c='A';

    int *p1 = &a;
    float *p2 = &b;
    char *p3 = &c;

    printf("Addresses of p1=%u, size = %lu\n", p1, sizeof(p1));
    printf("Addresses of p2=%u, size = %lu\n", p2, sizeof(p2));
    printf("Addresses of p3=%u, size = %lu\n", p3, sizeof(p3));
     
    return 0;


}
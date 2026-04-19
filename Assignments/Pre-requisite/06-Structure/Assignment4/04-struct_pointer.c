#include<stdio.h>

struct item
{
    char name[20];
    int quantity;
    float price;
    float amount;
};

int main()
{
    struct item i;
    struct item *p = &i;

    printf("Enter name quantity price: ");
    scanf("%s %d %f",p->name,&p->quantity,&p->price);

    p->amount = p->quantity * p->price;

    printf("Item: %s\n",p->name);
    printf("Amount: %.2f",p->amount);

    return 0;
}
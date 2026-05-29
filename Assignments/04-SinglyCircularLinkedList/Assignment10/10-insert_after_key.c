#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    char name[20];
    struct node *next;

} node_t;

node_t *head = NULL;

void create(int data, char name[])
{
    node_t *newnode, *temp;

    newnode = (node_t *)malloc(sizeof(node_t));

    newnode->data = data;
    strcpy(newnode->name, name);

    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->next = head;
    }
}

void insert_after_key(int key, int data, char name[])
{
    node_t *temp, *newnode;

    temp = head;

    do
    {
        if (temp->data == key)
        {
            newnode = (node_t *)malloc(sizeof(node_t));

            newnode->data = data;
            strcpy(newnode->name, name);

            newnode->next = temp->next;

            temp->next = newnode;

            return;
        }

        temp = temp->next;

    } while (temp != head);
}

void display()
{
    node_t *temp;

    temp = head;

    do
    {
        printf("|_%d_|_%s_| --> ",
               temp->data,
               temp->name);

        temp = temp->next;

    } while (temp != head);

    printf("HEAD\n");
}

int main()
{
    int key, data;
    char name[20];

    create(1, "AA");
    create(2, "BB");
    create(3, "CC");
    create(4, "DD");

    display();

    printf("Enter key : ");
    scanf("%d", &key);

    printf("Enter data and name : ");
    scanf("%d %s", &data, name);

    insert_after_key(key, data, name);

    display();

    return 0;
}
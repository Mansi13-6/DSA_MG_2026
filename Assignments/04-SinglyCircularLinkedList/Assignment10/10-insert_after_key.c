#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int id;
    char name[20];
    int num;
    struct node *next;

} node_t;

node_t *head = NULL;

void create(int id, char name[], int num)
{
    node_t *newnode, *temp;

    newnode = (node_t *)malloc(sizeof(node_t));

    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->num = num;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void insert_after_key(int key, int id, char name[], int num)
{
    node_t *temp, *newnode;

    temp = head;

    while (temp != NULL)
    {
        if (temp->id == key)
        {
            newnode = (node_t *)malloc(sizeof(node_t));

            newnode->id = id;
            strcpy(newnode->name, name);
            newnode->num = num;

            newnode->next = temp->next;

            temp->next = newnode;

            return;
        }

        temp = temp->next;
    }
}

void display()
{
    node_t *temp;

    temp = head;

    while (temp != NULL)
    {
        printf("|_%d_|_%s_|_%d_| --> ",
               temp->id,
               temp->name,
               temp->num);

        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int key, id, num;
    char name[20];

    create(1, "AA", 100);
    create(2, "BB", 200);
    create(3, "CC", 300);
    create(4, "DD", 500);

    display();

    printf("Enter key : ");
    scanf("%d", &key);

    printf("Enter id name num : ");
    scanf("%d %s %d", &id, name, &num);

    insert_after_key(key, id, name, num);

    display();

    return 0;
}
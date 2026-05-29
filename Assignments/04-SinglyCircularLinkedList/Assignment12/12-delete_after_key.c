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

void delete_after_key(int key)
{
    node_t *temp, *del;

    temp = head;

    while (temp != NULL)
    {
        if (temp->id == key)
        {
            del = temp->next;

            if (del == NULL)
            {
                return;
            }

            temp->next = del->next;

            free(del);

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
    int key;

    create(1, "AA", 100);
    create(2, "BB", 200);
    create(3, "CC", 300);
    create(4, "DD", 500);

    display();

    printf("Enter key : ");
    scanf("%d", &key);

    delete_after_key(key);

    display();

    return 0;
}
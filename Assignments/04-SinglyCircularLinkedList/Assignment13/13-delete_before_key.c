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

void delete_before_key(int key)
{
    node_t *temp, *prev, *del;

    if (head == NULL || head->next == NULL)
    {
        return;
    }

    if (head->next->id == key)
    {
        del = head;

        head = head->next;

        free(del);

        return;
    }

    prev = head;
    temp = head->next;

    while (temp->next != NULL)
    {
        if (temp->next->id == key)
        {
            del = temp;

            prev->next = temp->next;

            free(del);

            return;
        }

        prev = temp;
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

    delete_before_key(key);

    display();

    return 0;
}
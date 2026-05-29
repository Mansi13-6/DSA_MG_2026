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

void delete_before_key(int key)
{
    node_t *temp, *prev, *del, *last;

    if (head == NULL || head->next == head)
    {
        return;
    }

    if (head->next->data == key)
    {
        last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        del = head;

        head = head->next;

        last->next = head;

        free(del);

        return;
    }

    prev = head;
    temp = head->next;

    while (temp->next != head)
    {
        if (temp->next->data == key)
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
    int key;

    create(1, "AA");
    create(2, "BB");
    create(3, "CC");
    create(4, "DD");

    display();

    printf("Enter key : ");
    scanf("%d", &key);

    delete_before_key(key);

    display();

    return 0;
}
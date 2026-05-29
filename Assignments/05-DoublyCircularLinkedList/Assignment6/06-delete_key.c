#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;

} node_t;

node_t *head = NULL;

void create(int value)
{
    node_t *newnode, *temp;

    newnode = (node_t *)malloc(sizeof(node_t));

    newnode->data = value;

    if (head == NULL)
    {
        head = newnode;

        newnode->next = head;
        newnode->prev = head;
    }
    else
    {
        temp = head->prev;

        temp->next = newnode;

        newnode->prev = temp;
        newnode->next = head;

        head->prev = newnode;
    }
}

void delete_key(int key)
{
    node_t *temp;

    temp = head;

    do
    {
        if (temp->data == key)
        {
            temp->prev->next = temp->next;

            temp->next->prev = temp->prev;

            if (temp == head)
            {
                head = temp->next;
            }

            free(temp);

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
        printf("%d <--> ", temp->data);

        temp = temp->next;

    } while (temp != head);

    printf("HEAD\n");
}

int main()
{
    int n, i, value, key;

    printf("Enter number of nodes : ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter data : ");
        scanf("%d", &value);

        create(value);
    }

    display();

    printf("Enter key : ");
    scanf("%d", &key);

    delete_key(key);

    display();

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
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

void delete_position(int pos)
{
    node_t *temp, *prev;
    int i;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;

    if (pos == 1)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = head->next;

        free(head);

        head = temp->next;

        return;
    }

    temp = head;

    for (i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;

    free(temp);
}

void display()
{
    node_t *temp;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    temp = head;

    do
    {
        printf("%d ", temp->data);

        temp = temp->next;

    } while (temp != head);

    printf("\n");
}

int main()
{
    int pos;

    create(10);
    create(20);
    create(30);
    create(40);

    display();

    printf("Enter position to delete : ");
    scanf("%d", &pos);

    delete_position(pos);

    display();

    return 0;
}
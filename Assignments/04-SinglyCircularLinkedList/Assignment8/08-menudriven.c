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

void insert_start(int value)
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

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

void insert_end(int value)
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

void delete_start()
{
    node_t *temp, *last;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    last = head;

    while (last->next != head)
    {
        last = last->next;
    }

    head = head->next;

    last->next = head;

    free(temp);
}

void delete_end()
{
    node_t *temp, *prev;

    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;

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
    int choice, value;

    while (1)
    {
        printf("\n1.Create");
        printf("\n2.Insert Start");
        printf("\n3.Insert End");
        printf("\n4.Delete Start");
        printf("\n5.Delete End");
        printf("\n6.Display");
        printf("\n7.Exit");

        printf("\nEnter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("Enter value : ");
                scanf("%d", &value);

                create(value);

                break;

            case 2:

                printf("Enter value : ");
                scanf("%d", &value);

                insert_start(value);

                break;

            case 3:

                printf("Enter value : ");
                scanf("%d", &value);

                insert_end(value);

                break;

            case 4:

                delete_start();

                break;

            case 5:

                delete_end();

                break;

            case 6:

                display();

                break;

            case 7:

                exit(0);

            default:

                printf("Invalid Choice\n");
        }
    }

    return 0;
}
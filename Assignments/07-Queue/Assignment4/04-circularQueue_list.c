#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;

} queue_t;

queue_t *front = NULL;
queue_t *rear = NULL;

int isEmpty()
{
    return front == NULL;
}

void enqueue(int value)
{
    queue_t *newNode;

    newNode = (queue_t *)malloc(sizeof(queue_t));

    newNode->data = value;

    if (isEmpty())
    {
        front = rear = newNode;

        rear->next = front;
    }
    else
    {
        rear->next = newNode;

        rear = newNode;

        rear->next = front;
    }

    printf("%d inserted successfully\n", value);
}

void dequeue()
{
    queue_t *temp;

    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    if (front == rear)
    {
        printf("%d deleted\n", front->data);

        free(front);

        front = rear = NULL;

        return;
    }

    temp = front;

    printf("%d deleted\n", front->data);

    front = front->next;

    rear->next = front;

    free(temp);
}

void display()
{
    queue_t *temp;

    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    temp = front;

    printf("Queue elements are:\n");

    do
    {
        printf("%d\n", temp->data);

        temp = temp->next;

    } while (temp != front);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    enqueue(40);

    display();

    dequeue();
    dequeue();

    display();

    return 0;
}
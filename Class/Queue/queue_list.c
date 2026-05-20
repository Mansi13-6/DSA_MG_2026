#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct queue
{
    int data;
    struct queue *next;
} queue_t;


queue_t *front = NULL;
queue_t *rear = NULL;

int count = 0;

// Check if queue is empty
int isEmpty()
{
    return front == NULL;
}

// Check if queue is full
int isFull()
{
    return count == MAX;
}

// Enqueue operation
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }

    // Create new node
    queue_t *newnode = (queue_t *)malloc(sizeof(queue_t));

    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    count++;

    printf("%d inserted into queue\n", value);
}

// Dequeue operation
void dequeue()   
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return;
    }

    queue_t *temp = front;

    printf("%d deleted from queue\n", front->data);

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
    count--;
}

// Display queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }

    queue_t *temp = front;

    printf("Queue elements are:\n");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    enqueue(40);

    dequeue();
    display();

    dequeue();
    dequeue();

    dequeue(); 

    return 0;
}
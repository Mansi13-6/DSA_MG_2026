#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct queue
{
    int data;
    struct queue *next;
} queue_t;

int count = 0;

// Check if queue is empty
int isEmpty(queue_t *front)
{
    return front == NULL;
}

// Check if queue is full
int isFull()
{
    return count == MAX;
}

// Enqueue operation 
void enqueue(queue_t **front, queue_t **rear, int value)
{
    if (isFull())
    {
        printf("Queue Overflow\n");
        return;
    }

    queue_t *newnode = (queue_t *)malloc(sizeof(queue_t));

    newnode->data = value;
    newnode->next = NULL;

    // If queue is empty
    if (*front == NULL)
    {
        *front = *rear = newnode;
    }
    else
    {
        (*rear)->next = newnode;
        *rear = newnode;
    }

    count++;

    printf("%d inserted into queue\n", value);
}

// Dequeue operation 
void dequeue(queue_t **front, queue_t **rear)
{
    if (isEmpty(*front))
    {
        printf("Queue Underflow\n");
        return;
    }

    queue_t *temp = *front;

    printf("%d deleted from queue\n", (*front)->data);

    *front = (*front)->next;

    // If queue becomes empty
    if (*front == NULL)
    {
        *rear = NULL;
    }

    free(temp);
    count--;
}

// Display queue
void display(queue_t *front)
{
    if (isEmpty(front))
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
    queue_t *front = NULL;
    queue_t *rear = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 20);
    enqueue(&front, &rear, 30);

    display(front);

    enqueue(&front, &rear, 40);

    dequeue(&front, &rear);

    display(front);

    dequeue(&front, &rear);
    dequeue(&front, &rear);
    dequeue(&front, &rear);

    display(front);

    return 0;
}
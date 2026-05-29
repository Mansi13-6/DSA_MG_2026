#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct queue
{
    int arr[MAX];
    int front;
    int rear;

} queue_t;

void init_queue(queue_t *q)
{
    q->front = -1;
    q->rear = -1;
}

// Check Queue is Full
int isFull(queue_t *q)
{
    return (q->rear == MAX - 1);
}

// Check Queue is Empty
int isEmpty(queue_t *q)
{
    return (q->front == -1 || q->front > q->rear);
}

// Enqueue Operation
void enqueue(queue_t *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }

    if (q->front == -1)
    {
        q->front = 0;
    }

    q->rear++;
    q->arr[q->rear] = value;

    printf("Value %d inserted\n", value);
}

// Dequeue Operation
void dequeue(queue_t *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("%d deleted\n", q->arr[q->front]);

    q->front++;

    if (q->front > q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
}

// Display Queue
void display(queue_t *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements are:\n");

    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d\n", q->arr[i]);
    }
}

// Main Function
int main()
{
    queue_t q;

    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    dequeue(&q);

    display(&q);

    return 0;

}
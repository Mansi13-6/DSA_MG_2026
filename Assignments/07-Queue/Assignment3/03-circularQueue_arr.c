#include <stdio.h>

#define MAX 3

typedef struct queue
{
    int arr[MAX];
    int front;
    int rear;

} queue_t;

// Initialize Queue
void init_queue(queue_t *q)
{
    q->front = -1;
    q->rear = -1;
}

// Check queue is Full
int isFull(queue_t *q)
{
    return ((q->front == 0 && q->rear == MAX - 1) || (q->rear + 1 == q->front));
}

// Check queue is Empty
int isEmpty(queue_t *q)
{
    return (q->front == -1);
}

// Enqueue operation
void enqueue(queue_t *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }

    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        if (q->rear == MAX - 1)
        {
            q->rear = 0;
        }
        else
        {
            q->rear++;
        }
    }

    q->arr[q->rear] = value;

    printf("%d inserted\n", value);
}

// Dequeue operation
void dequeue(queue_t *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("%d deleted\n", q->arr[q->front]);

    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        if (q->front == MAX - 1)
        {
            q->front = 0;
        }
        else
        {
            q->front++;
        }
    }
}

// Display
void display(queue_t *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements are:\n");

    while (q->arr[q->front])
    {
        printf("%d\n", q->arr[q->front]);

        if (q->front == q->rear)
        {
            break;
        }
        if (q->front == MAX - 1)
        {
            q->front = 0;
        }
        else
        {
            q->front++;
        }
    }
}

// Main method
int main()
{
    queue_t q;

    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);
    display(&q);
    dequeue(&q);
    dequeue(&q);

    display(&q);

    enqueue(&q, 40);

    display(&q);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Queue Structure
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

// Check Queue Full
int isFull(queue_t *q)
{
    return (q->rear == MAX - 1);
}

// Check Queue Empty
int isEmpty(queue_t *q)
{
    return (q->front == -1 || q->front > q->rear);
}

int queueSize(queue_t *q)
{
    if (isEmpty(q))
        return 0;

    return (q->rear - q->front + 1);
}

// Enqueue
void enqueue(queue_t *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = value;
}

// Dequeue
int dequeue(queue_t *q)
{
    int value;

    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return -1;
    }

    value = q->arr[q->front];
    q->front++;

    if (q->front > q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }

    return value;
}

// Display Queue
void display(queue_t *q)
{
    int i;

    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue Elements: ");

    for (i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }

    printf("\n");
}

void reverseK(queue_t *q, int k)
{
    int value;
    if (k == 0)
        return;

    value = dequeue(q);

    reverseK(q, k - 1);

    enqueue(q, value);
}

// Function to reverse first k elements
void reverseFirstK(queue_t *q, int k)
{
    int size, i, value;

    size = queueSize(q);

    if (k <= 0 || k > size)
    {
        printf("Invalid value of k\n");
        return;
    }
    reverseK(q, k);

    for (i = 0; i < size - k; i++)
    {
        value = dequeue(q);
        enqueue(q, value);
    }
}

int main()
{
    queue_t q;
    int k;

    init_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("Original Queue:\n");
    display(&q);

    printf("Enter value of k: ");
    scanf("%d", &k);

    reverseFirstK(&q, k);

    printf("Queue after reversing first %d elements:\n", k);
    display(&q);

    return 0;
}
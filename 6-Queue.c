#include <stdio.h>

typedef struct
{
    int array[100000];
    int front;
    int back;
}
queue;

int dequeue(queue *q)
{
    int value;
    q->front += 1;

    value = q->array[q->front];
    return value;
}

// If we declare queue globally then we don't have to pass address
void enqueue(queue *q, int value)
{
    q->back += 1;
    q->array[q->back] = value;
}

int main(void)
{
    int value, x;
    queue q;
    q.front = -1;
    q.back = -1;

    // Enqueue
    value = 1;
    enqueue(&q, value);
    printf("%d\n", q.array[q.back]);

    value = 2;
    enqueue(&q, value);
    printf("%d\n", q.array[q.back]);

    value = 3;
    enqueue(&q, value);
    printf("%d\n", q.array[q.back]);

    // Dequeue
    x = dequeue(&q);
    printf("%d\n", x);

    x = dequeue(&q);
    printf("%d\n", x);

    x = dequeue(&q);
    printf("%d\n", x);

}

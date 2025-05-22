#include <stdio.h>
#include <stdlib.h>


typedef struct queue 
{
    int *arr; 
    int cap;
    int front;
    int size;
} Queue;

void initializeQ(Queue *q, int capacity)
{
    q->cap = capacity;
    q->arr = (int *)malloc(capacity * sizeof(int)); 
    q->front = 0;
    q->size = 0;
}

bool isFull(Queue *q)
{
    return q->size == q->cap;
}

bool isEmpty(Queue *q)
{
    return q->size == 0;
}

void enqueue(Queue *q, int x)
{
    if(isFull(q) == true)
    {
        printf("Q is full\n");
        return;
    }

    int rear = (q->front + q->size) % q->cap;
    q->arr[rear] = x;
    q->size++;

    return;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Q is empty\n");
        return -1;       
    }

    int ret = q->arr[q->front];
    q->front = (q->front+1) % q->cap;
    q->size--;

    return ret;
}

int front(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Q is empty\n");
        return -1;       
    }

    return q->arr[q->front];
}

int rear(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Q is empty\n");
        return -1;       
    }

    int rear = (q->front + (q->size-1)) % q->cap;

    return q->arr[rear];;
}

int main() 
{
    Queue q;
    initializeQ(&q, 4); 

    enqueue(&q, 1);
    printf("Front:%d, rear:%d\n", front(&q), rear(&q));
    enqueue(&q, 2);
    printf("Front:%d, rear:%d\n", front(&q), rear(&q));
    enqueue(&q, 3);
    printf("Front:%d, rear:%d\n", front(&q), rear(&q));
    enqueue(&q, 4);
    printf("Front:%d, rear:%d\n", front(&q), rear(&q));
    enqueue(&q, 5);
    printf("Front:%d, rear:%d\n", front(&q), rear(&q));
    printf("dequeue: %d\n", dequeue(&q));
    enqueue(&q, 5);
    printf("Front:%d, rear:%d\n", front(&q), rear(&q));
    enqueue(&q, 5);
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));


    return 0;
}
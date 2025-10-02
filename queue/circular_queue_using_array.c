#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100

typedef struct Queue
{
    int arr[MAX];
    int front;
    int rear;
    int size;
} Queue;

void initialise(Queue *q)
{
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

bool isEmpty(Queue *q)
{
    return q->size == 0;
}

bool isFull(Queue *q)
{
    return q->size == MAX;
}

void push(Queue *q, int val)
{
    if (isFull(q))
        return;
    if (q->size == 0)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear = (++q->rear) % MAX;
    }
    q->arr[q->rear] = val;
    q->size++;
}

int pop(Queue *q)
{
    if (isEmpty(q))
        return -1;
    int num = q->arr[q->front];
    if (q->size == 1)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (++q->front) % MAX;
    }
    q->size--;
    return num;
}

int peek(Queue *q)
{
    if (isEmpty(q))
        return -1;
    return q->arr[q->front];
}

int size(Queue* q)
{
    return q->size;
}

void printQueue(Queue *q)
{
    if (isEmpty(q))
        return;
    int i = q->front;
    for (int j = 1; j <= q->size; j++)
    {
        printf("%d ", q->arr[i]);
        i = (++i) % MAX;
    }
    printf("\n");
}

int main()
{
    Queue q;
    initialise(&q);
    push(&q, 4);
    push(&q, 3);
    push(&q, 8);
    printf("Size of queue is %d\n", size(&q));
    printf("Front element before pop is %d\n", pop(&q));
    printf("Front element after pop is %d\n", peek(&q));
    printQueue(&q);
}

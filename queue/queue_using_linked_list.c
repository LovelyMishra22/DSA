#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node* next;
}Node;

Node* getNode(int val)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

typedef struct Queue
{
    Node * front, * rear;
    int size;
}Queue;

void initialise(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int isEmpty(Queue* q)
{
    return q->size == 0;
}

void push(Queue* q, int val)
{
    Node* newNode = getNode(val);
    if(isEmpty(q) == 1) 
    {
        q->front = newNode;
        q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int pop(Queue* q)
{
    if(isEmpty(q) == 1) return -1;
    Node* temp = q->front;
    if(q->size == 1)
    {
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        q->front = q->front->next;
    }
    int num = temp->val;
    free(temp);
    q->size--;
    return num;
}

int peek(Queue* q)
{
    if(isEmpty(q) == 1) return -1;
    return q->front->val;
}

int size(Queue* q)
{
    return q->size;
}

void printQueue(Queue* q)
{
    if(isEmpty(q) == 1) return;
    Node* temp = q->front;
    while(temp!= NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
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

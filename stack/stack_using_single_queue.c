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

void initialiseQueue(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int isEmptyQueue(Queue* q)
{
    return q->size == 0;
}

void enqueue(Queue* q, int val)
{
    Node* newNode = getNode(val);
    if(isEmptyQueue(q) == 1) 
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

int dequeue(Queue* q)
{
    if(isEmptyQueue(q) == 1) return -1;
    Node* temp = q->front;
    if(q->size == 1)
    {
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

int peekQueue(Queue* q)
{
    if(q->size == 0) return -1;
    return q->front->val;
}

typedef struct Stack
{
    Queue q;
    int size;
}Stack;

void initialiseStack(Stack* st)
{
    initialiseQueue(&(st->q));
    st->size = 0;
}

bool isEmpty(Stack* st)
{
    return st->size == 0;
}

void push(Stack* st, int val)
{
    enqueue(&(st->q), val);
    st->size++;
    for(int i = 1; i < st->size; i++)
    {
        int num = dequeue(&(st->q));
        enqueue(&(st->q), num);
    }
}

int pop(Stack* st)
{
    if(isEmpty(st) == 1) return -1;
    st->size--;
    return dequeue(&(st->q));
}

int peek(Stack* st)
{
    if(isEmpty(st) == 1) return -1;
    //return peekQueue(&(st->q));
    return st->q.front->val;
}

int size(Stack* st)
{
    return st->size;
}

void printStack(Stack* st)
{
    if(isEmpty(st) == 1) return;
    Node* temp = st->q.front;
    while(temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Stack st;
    initialiseStack(&st);
    push(&st, 8);
    push(&st, 3);
    push(&st, 2);
    push(&st, 9);
    push(&st, 6);
    pop(&st);
    printStack(&st);
    printf("Size is %d\n", size(&st));
}

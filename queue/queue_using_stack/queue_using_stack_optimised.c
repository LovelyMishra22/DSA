// More optimised.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

Node *getNode(int val)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

typedef struct Stack
{
    Node *top;
    int size;
} Stack;

void initialiseStack(Stack *st)
{
    st->top = NULL;
    st->size = 0;
}

bool isEmptyStack(Stack *st)
{
    return st->size == 0;
}

void push(Stack *st, int val)
{
    Node *newNode = getNode(val);
    newNode->next = st->top;
    st->top = newNode;
    st->size++;
}

int pop(Stack *st)
{
    if (isEmptyStack(st) == 1)
        return -1;
    Node *temp = st->top;
    st->top = st->top->next;
    int num = temp->val;
    free(temp);
    st->size--;
    return num;
}

int peekStack(Stack *st)
{
    if (isEmptyStack(st) == 1)
        return -1;
    return st->top->val;
}

typedef struct Queue
{
    Stack st1, st2;
    int size;
} Queue;

void initialiseQueue(Queue *q)
{
    initialiseStack(&(q->st1));
    initialiseStack(&(q->st2));
    q->size = 0;
}

bool isEmpty(Queue *q)
{
    return q->size == 0;
}

void enqueue(Queue *q, int val)
{
    push(&(q->st1), val);
    q->size++;
}

int dequeue(Queue *q)
{
    if (isEmpty(q) == 1)
        return -1;
    if (q->st2.size == 0)
    {
        while (q->st1.size)
        {
            push(&(q->st2), pop(&(q->st1)));
        }
    }
    q->size--;
    return pop(&(q->st2));
}

int peek(Queue *q)
{
    if (isEmpty(q) == 1)
        return -1;
    if (q->st2.size == 0)
    {
        while (q->st1.size)
        {
            push(&(q->st2), pop(&(q->st1)));
        }
    }
    return peekStack(&(q->st2));
}

int size(Queue *q)
{
    return q->size;
}

void printQueue(Queue *q)
{
    if (isEmpty(q) == 1)
        return;
    while (q->st1.size)
    {
        push(&(q->st2), pop(&(q->st1)));
    }
    Node *temp = q->st2.top;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Queue q;
    initialiseQueue(&q);
    enqueue(&q, 4);
    enqueue(&q, 3);
    enqueue(&q, 8);
    printf("Size of queue is %d\n", size(&q));
    printQueue(&q);
    printf("Front element before dequeue is %d\n", dequeue(&q));
    printf("Front element after dequeue is %d\n", peek(&q));
    printQueue(&q);
}

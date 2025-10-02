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

typedef struct Stack
{
    Node* top;
    int size;
}Stack;

void initialise(Stack* st)
{
    st->top = NULL;
    st->size = 0;
}

bool isEmpty(Stack* st)
{
    return st->size == 0;
}

void push(Stack* st, int val)
{
    Node* newNode = getNode(val);
    newNode->next = st->top;
    st->top = newNode;
    st->size++;
}

int pop(Stack* st)
{
    if(isEmpty(st) == 1) return -1;
    Node* temp = st->top;
    st->top = st->top->next;
    int num = temp->val;
    free(temp);
    st->size--;
    return num;
}

int peek(Stack* st)
{
    if(isEmpty(st) == 1) return -1;
    return st->top->val;
}

int size(Stack* st)
{
    return st->size;
}

void printStack(Stack* st)
{
    if(st->top == NULL) return;
    Node* temp = st->top;
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
    initialise(&st);
    push(&st, 8);
    push(&st, 3);
    push(&st, 2);
    push(&st, 9);
    pop(&st);
    printStack(&st);
    printf("Size is %d\n", size(&st));
}

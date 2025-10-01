#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 1000

typedef struct Stack
{
    int arr[MAX];
    int top;
}Stack;

void initialise(Stack* stack)
{
    stack->top = -1;
}

bool isEmpty(Stack* stack)
{
    return stack->top == -1;
}

bool isFull(Stack* stack)
{
    return stack->top == MAX-1;
}

void push(Stack* stack, int val)
{
    if(isFull(stack) == 1) return;
    stack->arr[++stack->top] = val;
    return;
}

int pop(Stack* stack)
{
    if(isEmpty(stack) == 1) return -1;
    return stack->arr[stack->top--];
}

int peek(Stack* stack)
{
    if(isEmpty(stack) == 1) return -1;
    return stack->arr[stack->top];
}

void printStack(Stack* stack)
{
    if(isEmpty(stack) == 1) return;
    while(isEmpty(stack) != 1)
    {
        printf("%d ", pop(stack));
    }
    printf("\n");
}

int size(Stack* stack)
{
    if(stack->top == -1) return 0;
    return stack->top + 1;
}

int main()
{
    Stack stack;
    initialise(&stack);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 8);
    push(&stack, 1);
    printf("Top element is %d \n", peek(&stack));
    printf("Size is %d \n", size(&stack));
    printStack(&stack);
    return 0;
}

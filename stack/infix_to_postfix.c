/*
  gfg problem : infix to postfix

  You are given a string s representing an infix expression. Convert this infix expression to a postfix expression.
  
  Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
  Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
  Note: The precedence order is as follows: (^) has the highest precedence and is evaluated from right to left, (* and /) come next with left to right associativity, and (+ and -) have the lowest precedence with left to right associativity.
*/

#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
    char val;
    struct Node* next;
}Node;

Node* getNode(char val)
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

void push(Stack* st, char ch)
{
    Node* newNode = getNode(ch);
    newNode->next = st->top;
    st->top = newNode;
    st->size++;
}

char pop(Stack* st)
{
    if(st->size == 0) return '\0';
    Node* temp = st->top;
    st->top = st->top->next;
    char ch = temp->val;
    free(temp);
    st->size--;
    return ch;
}

char peek(Stack* st)
{
    if(st->size == 0) return '\0';
    return st->top->val;
}

int priority(char ch)
{
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return -1; // other operators priority.
}

char* infixToPostfix(char* s) {
    // code here
    int len = strlen(s);
    char* ans = calloc(len + 1, sizeof(char));
    int j = 0;
    Stack st;
    initialise(&st);
    for(int i = 0; i < len; i++)
    {
        if(('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z') || ('0' <= s[i] && s[i] <= '9')) // can't use format : ('a' <= s[i] <= 'z') in c
        {
            ans[j] = s[i];
            j++;
        }
        else if(isEmpty(&st) == 1 || s[i] == '(') 
        {
            push(&st, s[i]);
        }
        else if(s[i] == ')') // pop all elements from stack and put it in ans.
        {
            while(peek(&st) != '(')
            {
                ans[j] = pop(&st);
                j++;
            }
            pop(&st);
        }
        else
        {
            while(priority(s[i]) < priority(peek(&st))) // loop until priority of s[i] >= to top element of stack.
            {
                ans[j] = pop(&st);
                j++;
            }
            if(priority(s[i]) > priority(peek(&st)))
            {
                push(&st, s[i]);
            }
            else if(priority(s[i]) == priority(peek(&st)))
            {
                if(s[i] == '^') // right to left assosciativity.
                {
                    push(&st, s[i]);
                }
                else //others having left to right assosciativity.
                {
                    while((isEmpty(&st) == 0) && ( priority(s[i]) == priority(peek(&st)) ) ) // check if stack is empty then break the loop.
                    {
                        ans[j] = pop(&st);
                        j++;
                    }
                    push(&st, s[i]);   
                }
                
            }
        }
    }
    while(isEmpty(&st) == 0) // pop all elements and put them in ans.
    {
        ans[j] = pop(&st);
        j++;
    }
    ans[j] = '\0';
    return ans;
}

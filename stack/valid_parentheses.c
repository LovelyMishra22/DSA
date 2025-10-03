/*
  leetcode : 20
  
  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
  
  An input string is valid if:
  
  Open brackets must be closed by the same type of brackets.
  Open brackets must be closed in the correct order.
  Every close bracket has a corresponding open bracket of the same type.
   
  
  Example 1:
  Input: s = "()"
  Output: true
  
  Example 2:
  Input: s = "()[]{}"
  Output: true
  
  Example 3:
  Input: s = "(]"
  Output: false
  
  Example 4:
  Input: s = "([])"
  Output: true
  
  Example 5:
  Input: s = "([)]"
  Output: false
*/

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

void initialiseStack(Stack* st)
{
    st->top = NULL;
    st->size = 0;
}

void push(Stack* st, char val)
{
    Node* newNode = getNode(val);
    newNode->next = st->top;
    st->top = newNode;
    st->size++;
}

char pop(Stack* st)
{
    if(st->size == 0) return '\0';
    Node* temp = st->top;
    if(st->size == 1)
    {
        st->top = NULL;
    }
    else
    {
        st->top = st->top->next;
    }
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

bool isEmpty(Stack* st)
{
    return st->size == 0;
}

bool isValid(char* s) {
    Stack st;
    initialiseStack(&st);
    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(&st, s[i]);
        }
        else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if(s[i] == ')' && peek(&st) == '(')
            {
                pop(&st);
            }
            else if(s[i] == ']' && peek(&st) == '[')
            {
                pop(&st);
            }
            else if(s[i] == '}' && peek(&st) == '{')
            {
                pop(&st);
            }
            else return 0;
        }
    }
    return isEmpty(&st);
}

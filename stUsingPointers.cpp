#include <iostream>
#include <malloc.h>

using namespace std;

struct Node
{
    int value;
    Node *next;
    
};

bool isEmpty(Node *p)
{
    return p == NULL;
}

void push(Node **top, int value)
{
    Node *p;
    p = (Node*)malloc(sizeof(Node));
    p->value = value;
    p->next = *top;
    *top = p;
    cout << "Item has been inserted!" << endl;
    
}

int peek(Node *top)
{
    if(isEmpty(top))
    {
        cout << "Stack is empty!" << endl;
    }
    
    return top->value;
}

int pop(Node **top)
{
    Node *p;
    int item;
    if (isEmpty(*top))
    {
        cout << "Stack is empty!" << endl;
    }
    else
    {
        item = (*top)->value;
        p = *top;
        *top = (*top)->next;
        free(p);
    }
    return item;
}

int main()
{
    Node *top;
    top = NULL;
    
    push(&top, 1);
    push(&top, 2);
    
    int x = peek(top);
    cout << x << endl;
    
    push(&top, 3);
    x = peek(top);
    cout << x << endl;
    
    for (int i = 0; i < 3; i++)
    {
        x = pop(&top);
        cout << x << endl;
    }
    
    return 0;
    
}

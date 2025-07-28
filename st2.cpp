#include <iostream>
#include <malloc.h>

using namespace std;

struct Node
{
    int value;
    Node *prev;
    Node *next;
};

bool isEmpty(Node *p)
{
    return p == NULL;
}

void push(Node **p, int value)
{
    Node *p1, *p2;

    p1 = (Node*)malloc(sizeof(Node));
    p1->prev = NULL;
    p1->next = NULL;

    if (*p == NULL)
    {
        *p = p1;
        p1->prev = *p;
    }
    else
    {
        p2 = *p;
        while (p2->next != NULL)
        {
            p2 = p2->next;
        }
        p2->next = p1;
        p1->prev = p2;
    }
}

int pop(Node **p)
{
    Node *p1;
    int poppedValue;

    if(isEmpty(*p))
    {
        cout << "Stack is Empty!" << endl;
    }
    else
    {
        p1 = *p;
        while (p1->next != NULL)
        {
            p1 = p1->next;
        }
        poppedValue = p1->value;
        if (p1->prev != NULL)
        {
            p1->prev->next = NULL;
        }
        free(p1);
    }
    return poppedValue;
}

int main()
{
    Node *start;
    start = NULL;
    int v;

    push(&start, 1);
    push(&start, 2);
    v = pop(&start);
    cout << v << endl;
}

#include <iostream>
#include <malloc.h>

using namespace std;

struct Node *
{
    int value;
    Node *next;
};

bool isEmpty(Node* front, Node *rear)
{
    return front == NULL && rear == NULL;
}

void insertItem(Node **pFront, Node **pRear, int item)
{
    Node *p;

    p = (Node *)malloc(sizeof(Node));
    p->value = item;
    p->next = NULL;

    if (isEmpty(*pFront, *pRear))
    {
        *pFront = p;
        *pRear = p;
    }
    else
    {
        (*pRear)->next = p;
        *pRear = p;
        cout << "Item has been inserted!" << endl;
    }
}

int deleteItem(Node **pFront, Node **rear)
{
    Node *p;
    int item;
    if (isEmpty(*pFront, *pRear))
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    else
    {
        item = (*pFront)->value;
        p = *pFront;
        *pFront = (*pFront)->next;
        if (*pFront == NULL)
        {
            *pRear = NULL;
        }
        free(p);
        cout << "Item removed!";
    }
    return item;

}

int peek(Node *front, Node *rear)
{
    if (isEmpty(front, rear))
    {
        cout << "Queue is empty!" << endl;
    }
    
    return front->value; 
}

int main()
{
   
}

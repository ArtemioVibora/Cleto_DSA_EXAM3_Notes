#include <iostream>

using namespace std;

struct Node 
{
    int value;
    Node *next;
    Node *prev;

};

bool isEmpty(Node *pStart)
{
    return pStart == NULL;
}

void addElement(Node **pStart, int data)
{
    Node *ptr, *ptr2;

    ptr = (Node *)malloc(sizeof(Node));
    ptr->value = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (*pStart == NULL)
    {
        *pStart = ptr;
        ptr->prev = *pStart;
        cout << "Element has been inserted " << endl;
    }
    else
    {
        ptr2 = *pStart;
        while (ptr2->next != NULL)
        {
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr;
        ptr->prev = ptr2;
        cout << "Element has been inserted " << endl;
    }
}

void printElements(Node *pStart)
{
    Node *ptr;
    ptr = pStart;
    if (isEmpty(pStart))
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        while (ptr !=NULL)
        {
            cout << ptr->value << endl;
            ptr = ptr->next;
        }
    }
}

int main()
{
    Node *start;
    start = NULL;

    addElement(&start, 10);
    addElement(&start, 20);
    printElements(start);
}
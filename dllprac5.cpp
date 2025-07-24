#include <iostream>

using namespace std;

struct Node 
{
    int value;
    Node *next;
    Node *prev;
};

bool isEmpty(Node *p)
{
    return p == NULL;
}

void addElement(Node **p, int data)
{
    Node *ptr, *ptr2;

    ptr = (Node *)malloc(sizeof(Node));
    ptr->value = data;
    ptr->next = NULL;
    ptr->prev = NULL;

    if (*p == NULL)
    {
        *p = ptr;
        ptr->prev = *p;
    }
    else
    {
        ptr2 = *p;
        while (ptr2->next != NULL)
        {
            ptr2 = ptr2->next;
        }
        ptr2->next = ptr;
        ptr->prev = ptr2;
    }
}

void printAllElements(Node *p)
{
    Node *p1; 
    if (isEmpty(p))
    {
        cout << "List is Empty!" << endl;
    }
    else
    {
        p1 = p;
        while (p1 != NULL)
        {
            cout << p1->value << endl;
            p1 = p1->next;
        }
    }
}

int main()
{
    Node *s;
    s = NULL; 
    addElement(&s, 10);
    addElement(&s, 30);
    addElement(&s, 40);
    addElement(&s, 110);
    printAllElements(s);
}
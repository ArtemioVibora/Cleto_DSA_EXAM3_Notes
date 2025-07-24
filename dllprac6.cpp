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
    Node *p1, *p2;

    p1 = (Node *)malloc(sizeof(Node));
    p1->value = data;
    p1->next = NULL;
    p1->prev = NULL;

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

void printAllElements(Node *p)
{
    Node *p1;
    if (isEmpty(p))
    {
        cout << "This is empty!" << endl;
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
    addElement(&s, 100);
    addElement(&s, 190);
    addElement(&s, 6);
    printAllElements(s);

}

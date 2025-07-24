#include <iostream>
#include <malloc.h>

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

    p1 = (Node*)malloc(sizeof(Node));
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

void deleteElement(Node **p, int data)
{
    Node *discard, *before;
    discard = *p;
    before = NULL;

    if (isEmpty(*p))
    {
        cout << "It is empty!" << endl;
        return;
    }
    else
    {
        if (discard->value == data)
        {
            *p = discard->next;
            if (*p != NULL)
            {
                (*p)-> prev = NULL;
            }
            free(discard);
            cout << "Item deleted!" << endl;
            return;
        }
        while (discard != NULL && discard->value != data)
        {
            before = discard;
            discard = discard->next;
        }
        if (discard == NULL)
        {
            cout << "Node does not exist!" << endl;
        }
        else
        {
            before->next = discard->next;
            if (discard->next != NULL)
            {
                discard->next->prev = before;
            }
            free(discard);
        }
    }
}

void printElement(Node *p)
{
    Node *p1;

    if(isEmpty(p))
    {
        cout << "It is empty!" << endl;
    }
    else
    {
        p1 = p->next;
        while(p1 != NULL)
        {
            cout << p1->value << endl;
            p1 = p1->next;
        }
    }
}


int main()
{
    Node *s;
    addElement(&s, 1);
    addElement(&s, 2);
    printElement(s);
    deleteElement(&s, 2);
    addElement(&s, 3);
    cout << "----" << endl;
    printElement(s);

}
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

void addElementRear(Node **p, int value)
{
    Node *p1, *p2;

    p1 = (Node*)malloc(sizeof(Node));
    p1->value = value;
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

void deleteElement(Node **p, int value)
{
    Node *discard, *before;
    before = NULL;
    discard = *p;

    if (isEmpty(*p))
    {
        cout << "List is empty!" << endl;
    }
    else
    {
        if (discard->value == value)
        {
            *p = discard->next;
            if ((*p)->next != NULL)
            {
                (*p)->prev = NULL;
            }
            free(discard);
            return;
        }
        while (discard != NULL && discard->value != value)
        {
            before = discard;
            discard = discard->next;
        }
        if (discard == NULL)
        {
            cout << "Element does not exist!" << endl;
        }
        else
        {
            before->next = discard->next;
            if (discard->next != NULL)
            {
                discard->next->prev = before;
            }
            free(discard);

            cout << "Item has been deleted" << endl;
        }
    }
}

int main()
{
    Node *s;
    s = NULL;

    addElementRear(&s, 1);
    addElementRear(&s, 1);
}

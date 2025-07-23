#include <iostream>
#include <malloc.h>

using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

bool isEmpty(Node *start)
{
    if (start == NULL)
    {
        return true;
    }
    return false;
}

void addElement(int data, Node **pStart)
{
    Node *ptr, *newPtr;

    newPtr = (Node *)malloc(sizeof(Node));
    newPtr->value = data;
    newPtr->next = NULL;
    newPtr->prev = NULL;

    if (*pStart == NULL)
    {
        *pStart = newPtr;
    }
    else
    {
        ptr = *pStart;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newPtr;
        newPtr->prev = ptr;
    }
}

void removeElement(int pos, Node **pStart)
{
    Node *ptr, *before, *here;
    int ctr;

    ctr = 1;
    ptr = *pStart;

    if (isEmpty(*pStart))
    {
        cout << "List is empty" << endl;
    }
    else
    {
        if (ptr->prev == NULL && ptr->next == NULL)
        {
            here = ptr;
            free(here);
            *pStart = NULL;
        }
        else
        {


            while (ptr != NULL && ctr != pos )
            {
                ptr = ptr->next;
                ctr++;
            }
        }
    }
}

int main()
{

}
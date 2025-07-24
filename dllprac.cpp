#include <iostream>
#include <malloc.h>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node *prev;

};

int main()
{
    Node start;
    Node ptr;
    Node ptr2;
    Node ptr3;
    Node *ptrA;

    start.next = NULL;

    ptr.value = 10;
    ptr.next = NULL;
    ptr.prev = NULL;

    start.next = &ptr;
    ptr.prev = &start; 

    //in comes ptr2    
    ptr2.value = 20;
    ptr2.next = NULL;
    ptr2.prev = NULL;

    ptr.next = &ptr2;
    ptr2.prev = &ptr;

    //in comes ptr3    
    ptr3.value = 30;
    ptr3.next = NULL;
    ptr3.prev = NULL;

    ptr2.next = &ptr3;
    ptr3.prev = &ptr2;

    ptrA = &start;
    int ctr = 1;
    while (ptrA->next != NULL)
    {
        
        ptrA = ptrA->next;
        cout << ctr << ". " << ptrA->value << endl;
        ctr++;
    }
    ctr = 1;

    // Create node ptrB

    Node *ptrB, *here;
    int ctr2 = 1;

    ptrB = &start;

    //Assume we want to remove second element
    /*
    while (ptrB != NULL && ctr2 != 2)
    {
        ptrB = ptrB->next;
        ctr2++;
    }
    if (ptrB == NULL)
    {
        cout << "Element does not exist!" << endl;
    }
    else
    {
        ptr.next = ptr2.next;
        ptr3.prev = ptr2.prev;
        free(&ptr2);
    }

    while (ptrA->next != NULL)
    {
        
        ptrA = ptrA->next;
        cout << ctr << ". " << ptrA->value << endl;
        ctr++;
    }
        */

}
#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next;
    Node *prev;

};

int main()
{
    Node n1, n2, start;

    Node *ptr;
    ptr = &start;

    start.next = &n1;
    start.prev = NULL;

    n1.next = &n2;
    n1.prev = &start;

    n2.next = NULL;
    n2.prev = &n1;
    
    n1.value = 10;
    n2.value = 20;

    cout << "Forward printing LMAO" << endl;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        cout << ptr->value << endl;
    }

    cout << "Backward printing LMAO" << endl;

    while (ptr->prev != NULL)
    {
        cout << ptr->value << endl;
        ptr = ptr->prev;
    }
}

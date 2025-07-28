#include <iostream>

using namespace std;

const int MAX = 5;

bool isFull(int front, int rear)
{
    return ((rear + 1) % MAX) == front;
}

bool isEmpty(int front, int rear)
{
    return front == -1;
}

void insertItem(int queue[], int &front, int &rear, int data)
{
    if (isFull(front, rear))
    {
        cout << "List is full!" << endl;
        return;
    }
    
    if (isEmpty(front, rear))
    {
        front = rear = 0;
    }
    else 
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = item;
    cout << "Enqueued: " << item << endl; 
}

int removedItem(int queue[]. int &front, int &rear)
{
    if (isEmpty(front, rear))
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    int item = queue[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }

    cout << "Removed : " << item << endl;
    return item;
    
}

int frontItem(int queue[], int front, int rear)
{
    if (isEmpty(front, rear))
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return queue; 
}

void display(int queue[], int front, int rear)
{
    if (isEmpty(front, rear))
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue contents: ";
    int i = front;
    while (true)
    {
        cout << queue[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main()
{

}

#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

bool isFull(int front, int rear) {
    return ((rear + 1) % MAX_SIZE) == front;
}


bool isEmpty(int front, int rear)
{
    return front == rear;
}

void insertItem(int queue[], int front, int &ptr_rear, int item)
{
    if (isFull(front, ptr_rear))
    {
        cout << "List is full!" << endl;
    }
    else
    {
        if (ptr_rear == MAX_SIZE - 1)
        {
            ptr_rear = 0;
        }
        else
        {
            ++ptr_rear;

        }

        queue[ptr_rear] = item;
        cout << "Item has been inserted!" << endl;
    }
}

int removeItem(int queue[], int &ptr_front, int rear)
{
    int item;

    if  (isEmpty(ptr_front, rear))
    {
        cout << "List is empty!" << endl;
    }
    else
    {
        if (ptr_front == MAX_SIZE - 1)
        {
            ptr_front = 0;
        }
        else
        {
            ++ptr_front;
        }
        item = queue[ptr_front];
        cout << "Item has been removed!" << endl;
        
    }
    return item;
}

int front_item(int queue[], int front, int rear)
{
    if (isEmpty(front, rear))
    {
        cout << "The list is empty!" << endl;
    }
    else
    {
        if (front == MAX_SIZE - 1)
            return queue[0];
    }
    return queue[front + 1]; 
}

int main()
{
    int front, rear;
    rear = -1;
    front = -1; 

    int queue[MAX_SIZE];
    
    insertItem(queue, front, rear, 1);
    insertItem(queue, front, rear, 2);
    insertItem(queue, front, rear, 3);
    insertItem(queue, front, rear, 4);
    insertItem(queue, front, rear, 5);


    for (int i = 0; i < MAX_SIZE; i++)
    {
        cout << queue[i] << endl;
    }

    int rItem;
    int r2Item;
    rItem = removeItem(queue, front, rear);
    cout << rItem << endl;
    rItem = removeItem(queue, front, rear);

    insertItem(queue, front, rear, 31);
    r2Item = removeItem(queue, front, rear);
    insertItem(queue, front, rear, 100);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        cout << queue[i] << endl;
    }
    

}

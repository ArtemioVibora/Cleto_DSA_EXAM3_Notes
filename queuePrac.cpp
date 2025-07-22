#include <iostream>

using namespace std;

const int MAX = 10;

bool isEmpty(int rear)
{

    if (rear == -1)
    {
        return true;
    }
    return false;
}

bool isFull(int rear)
{
    if (rear == MAX - 1)
    {
        return true;
    }
    return false;
}

void addElement(int &first, int &rear, int data, int arr[])
{
    if (isFull(rear))
    {
        cout << "List is full!" << endl;
    }
    else if(rear == MAX -1 && first == MAX - 1)
    {
        cout << "Automatically resetting list" << endl;
        rear = -1;
        first = -1;
    }
    else
    {
        if (first == -1)
        {
            ++first;
            ++rear;
            arr[first] = data;
        }
        else
        {
            ++rear;
            arr[rear] = data;
        }
    }
}

void deleteElement(int &first, int &rear, int arr[])
{
    if (isEmpty(rear))
    {
        cout << "List is empty" << endl;
    }
    else
    {
        if (first == 0 && rear == 0)
        {
            --first;
            --rear;
        }
        else
        {
            ++first;
        }
    }

}

void printElement(int first, int rear, int arr[])
{
    for (int i = first; i <= rear; i++)
    {
        cout << arr[i] << "  ";       

    }
    cout << endl;
}

void resetList(int &first, int &rear)
{
    rear = -1;
    first = -1;
}


int main()
{
    int first, rear;
    first = rear = -1;

    int n = 10;
    int arr[MAX];
    
    addElement(first, rear, 1,  arr);
    addElement(first, rear, 2, arr);
    addElement(first, rear, 3, arr);
    printElement(first, rear, arr);
    deleteElement(first, rear, arr);
    printElement(first, rear, arr);


}

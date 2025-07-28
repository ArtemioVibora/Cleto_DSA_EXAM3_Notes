#include <iostream>

using namespace std;

const int MAX = 5;

bool isEmpty(int top)
{
    return top == -1;
}

bool isFull(int top)
{
    return top == MAX - 1;
}

void push(int stack[], int &top, int value)
{
    if(isFull(top))
    {
        cout << "Stack is full" << endl;
        return;
    }
    else
    {
        ++top;
        stack[top] = value;
        return;
    }
}

int pop(int stack[], int &top)
{
    int poppedItem;
    if (isEmpty(top))
    {
        cout << "Stack is empty!";
        return -1;
    }
    else
    {
        poppedItem = stack[top];
        --top;
    }
    return poppedItem;
}

void peek(int stack[], int top)
{
    if (isEmpty(top))
    {
        cout << "Stack is empty! Nothing to see here bro!" << endl;
        return; 
    }
    else
    {
        cout << stack[top] << endl;
    }
}

void runProgram()
{
    int top = -1;
    int stack[MAX];

    int input;
    int value;
    input = value = 0;

    bool flag = true;

    while (flag)
    {
        cout << "<1>Push\n<2>Pop\n<3>Peek\n";
        cout << "Enter choice: ";
        cin >> input;
        switch(input)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(stack, top, value);
                break;
            case 2:
                value = pop(stack, top);
                cout << "Value popped: " << value << endl;
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                flag = false;
                break;
            default:
                break;
        }
    }
}

int main()
{
    runProgram();
}

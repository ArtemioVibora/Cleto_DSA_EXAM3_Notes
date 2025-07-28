#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

bool isFull(int front, int rear) {
    return ((rear + 1) % MAX_SIZE) == front;
}

bool isEmpty(int front, int rear) {
    return front == -1;
}

void insertItem(int queue[], int &front, int &rear, int item) {
    if (isFull(front, rear)) {
        cout << "Queue is full!" << endl;
        return;
    }

    if (isEmpty(front, rear)) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }

    queue[rear] = item;
    cout << "Inserted: " << item << endl;
}

int removeItem(int queue[], int &front, int &rear) {
    if (isEmpty(front, rear)) {
        cout << "Queue is empty!" << endl;
        return -1; // Sentinel
    }

    int item = queue[front];

    if (front == rear) {
        // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    cout << "Removed: " << item << endl;
    return item;
}

int front_item(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        cout << "Queue is empty!" << endl;
        return -1;
    }

    return queue[front];
}

void display(int queue[], int front, int rear) {
    if (isEmpty(front, rear)) {
        cout << "Queue is empty!" << endl;
        return;
    }

    cout << "Queue contents: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    cout << endl;
}

int main() {
    int queue[MAX_SIZE];
    int front = -1, rear = -1;

    insertItem(queue, front, rear, 1);
    insertItem(queue, front, rear, 2);
    insertItem(queue, front, rear, 3);
    insertItem(queue, front, rear, 4);
    insertItem(queue, front, rear, 5); // Should say "full"

    display(queue, front, rear);

    removeItem(queue, front, rear);
    removeItem(queue, front, rear);

    insertItem(queue, front, rear, 6);
    insertItem(queue, front, rear, 7); // This should now work

    display(queue, front, rear);

    cout << "Front item is: " << front_item(queue, front, rear) << endl;

    return 0;
}

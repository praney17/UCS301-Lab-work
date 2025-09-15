#include <iostream>
using namespace std;

#define MAX 5

int arr[MAX];
int front = -1, rear = -1;

int isEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

int isFull() {
    if ((rear + 1) % MAX == front)
        return 1;
    else
        return 0;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Queue Overflow! Cannot insert " << x << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    arr[rear] = x;
    cout << x << " enqueued into the circular queue.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow! Cannot dequeue.\n";
        return;
    }
    cout << arr[front] << " dequeued from the circular queue.\n";
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty, nothing to peek.\n";
        return;
    }
    cout << "Front element: " << arr[front] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Circular Queue elements: ";
    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if (isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;
            case 6:
                if (isFull())
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

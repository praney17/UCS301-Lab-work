#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow!\n";
        return;
    }
    if (front == -1) front = 0;
    arr[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow!\n";
        return -1;
    }
    return arr[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void interleaveQueue() {
    int n = size();
    if (n % 2 != 0) {
        cout << "Queue has odd number of elements, cannot interleave!\n";
        return;
    }

    int half = n / 2;
    int firstHalf[MAX], secondHalf[MAX];
    int idx1 = 0, idx2 = 0;

    // Split into two halves
    for (int i = 0; i < half; i++) {
        firstHalf[idx1++] = dequeue();
    }
    for (int i = 0; i < half; i++) {
        secondHalf[idx2++] = dequeue();
    }

    // Interleave them back into queue
    for (int i = 0; i < half; i++) {
        enqueue(firstHalf[i]);
        enqueue(secondHalf[i]);
    }
}

int main() {
    int n, x;
    cout << "Enter number of elements (even): ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        enqueue(x);
    }

    cout << "Original Queue: ";
    display();

    interleaveQueue();

    cout << "Interleaved Queue: ";
    display();

    return 0;
}

#include <iostream>
using namespace std;

#define MAX 100

int q1[MAX], q2[MAX];
int f1 = -1, r1 = -1, f2 = -1, r2 = -1;

void enqueue1(int x) {
    if (r1 == MAX - 1) return;
    if (f1 == -1) f1 = 0;
    q1[++r1] = x;
}
int dequeue1() {
    if (f1 == -1 || f1 > r1) return -1;
    return q1[f1++];
}

void enqueue2(int x) {
    if (r2 == MAX - 1) return;
    if (f2 == -1) f2 = 0;
    q2[++r2] = x;
}
int dequeue2() {
    if (f2 == -1 || f2 > r2) return -1;
    return q2[f2++];
}

int isEmpty1() { return (f1 == -1 || f1 > r1); }
int isEmpty2() { return (f2 == -1 || f2 > r2); }

void reset2() { f2 = r2 = -1; }

void push(int x) {
    enqueue2(x);
    while (!isEmpty1()) {
        enqueue2(dequeue1());
    }
    f1 = f2; r1 = r2;
    for (int i = f2; i <= r2; i++) q1[i] = q2[i];
    reset2();
}

int pop() {
    if (isEmpty1()) {
        cout << "Stack Underflow\n";
        return -1;
    }
    return dequeue1();
}

void display() {
    if (isEmpty1()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = f1; i <= r1; i++) cout << q1[i] << " ";
    cout << endl;
}

int main() {
    int choice, val;
    do {
        cout << "\n--- Stack using Two Queues ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n0. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; push(val); break;
            case 2: val = pop(); if (val != -1) cout << "Popped: " << val << endl; break;
            case 3: display(); break;
        }
    } while (choice != 0);
    return 0;
}

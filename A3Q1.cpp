#include <iostream>
using namespace std;

const int MAX = 100;
int stackArr[MAX];
int top = -1;

void isEmpty() {
    if (top == -1)
        cout << "Stack is Empty.\n";
    else
        cout << "Stack is NOT Empty.\n";
}

void isFull(int n) {
    if (top == n - 1)
        cout << "Stack is Full.\n";
    else
        cout << "Stack is NOT Full.\n";
}

void push(int n) {
    if (top == n - 1) {
        cout << "Stack Overflow! Cannot push more elements.\n";
    } else {
        int val;
        cout << "Enter value to push: ";
        cin >> val;
        stackArr[++top] = val;
        cout << val << " pushed into the stack.\n";
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Nothing to pop.\n";
    } else {
        cout << stackArr[top] << " popped from the stack.\n";
        top--;
    }
}

void peek() {
    if (top == -1) {
        cout << "Stack is empty, nothing to peek.\n";
    } else {
        cout << "Top element is: " << stackArr[top] << endl;
    }
}

void display() {
    if (top == -1) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements are:\n";
        for (int i = top; i >= 0; i--) {
            cout << stackArr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, n;
    while (true) {
        cout << "Enter size of stack (max " << MAX << "): ";
        cin >> n;
        if (n > 0 && n <= MAX) break;
        else cout << "Invalid size! Please enter again.\n";
    }

    while (true) {
        cout << "\n----- MENU -----\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: push(n); break;
            case 2: pop(); break;
            case 3: isEmpty(); break;
            case 4: isFull(n); break;
            case 5: display(); break;
            case 6: peek(); break;
            case 7: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

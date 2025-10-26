#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;
char stackArr[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!\n";
    } else {
        stackArr[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        cout << "Stack Underflow!\n";
        return '\0';
    } else {
        return stackArr[top--];
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    for (char c : str) {
        push(c);
    }

    cout << "Reversed string: ";
    while (top != -1) {
        cout << pop();
    }
    cout << endl;

    return 0;
}

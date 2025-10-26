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
        return '\0';
    } else {
        return stackArr[top--];
    }
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

void checkBalanced(string expr) {
    top = -1; 
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            char topChar = pop();
            if (!isMatchingPair(topChar, c)) {
                cout << "Not Balanced\n";
                return;
            }
        }
    }
    if (top == -1)
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
}

int main() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    checkBalanced(expr);

    return 0;
}

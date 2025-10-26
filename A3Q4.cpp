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

char peek() {
    if (top == -1) return '\0';
    return stackArr[top];
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfix(string infix) {
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix += pop();
            }
            if (top != -1 && peek() == '(')
                pop();
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix += pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix += pop();
    }

    cout << "Postfix Expression: " << postfix << endl;
}

int main() {
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;

    infixToPostfix(infix);

    return 0;
}

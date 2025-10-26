#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

const int MAX = 100;
int stackArr[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!\n";
    } else {
        stackArr[++top] = val;
    }
}

int pop() {
    if (top == -1) {
        cout << "Stack Underflow!\n";
        return 0;
    } else {
        return stackArr[top--];
    }
}

int evaluatePostfix(string expr) {
    for (char c : expr) {
        if (isdigit(c)) {
            push(c - '0');
        }
        else {
            int val2 = pop();
            int val1 = pop();
            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(pow(val1, val2)); break;
            }
        }
    }
    return pop();
}

int main() {
    string expr;
    cout << "Enter Postfix Expression: ";
    cin >> expr;
    int result = evaluatePostfix(expr);
    cout << "Result = " << result << endl;
    return 0;
}

#include <iostream>
using namespace std;

#define MAX 100

char q[MAX];
int front = -1, rear = -1;
int freq[256] = {0};

void enqueue(char ch) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    q[++rear] = ch;
}

void dequeue() {
    if (front == -1 || front > rear) return;
    front++;
}

char getFront() {
    if (front == -1 || front > rear) return '\0';
    return q[front];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void firstNonRepeating(string s) {
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        freq[ch]++;
        enqueue(ch);
        while (!isEmpty() && freq[getFront()] > 1) {
            dequeue();
        }
        if (isEmpty())
            cout << -1 << " ";
        else
            cout << getFront() << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    firstNonRepeating(s);
    return 0;
}

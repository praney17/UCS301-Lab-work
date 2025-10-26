#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
    Node* last;
public:
    CircularLinkedList() {
        last = nullptr;
    }

    void insertLast(int val) {
        Node* newNode = new Node(val);
        if (last == nullptr) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void displayWithHeadRepeated() {
        if (last == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* head = last->next;
        Node* temp = head;
        cout << "Circular Linked List (head repeated): ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << "\n";
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertLast(10);
    cll.insertLast(20);
    cll.insertLast(30);
    cll.insertLast(40);
    cll.displayWithHeadRepeated();
    return 0;
}

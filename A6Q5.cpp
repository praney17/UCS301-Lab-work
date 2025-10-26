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

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void insertLast(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void makeCircular() {
        if (head == nullptr) return;
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = head;
    }

    bool isCircular() {
        if (head == nullptr)
            return false;
        Node* temp = head->next;
        while (temp != nullptr && temp != head)
            temp = temp->next;
        return (temp == head);
    }
};

int main() {
    LinkedList list;
    list.insertLast(10);
    list.insertLast(20);
    list.insertLast(30);
    list.insertLast(40);

    cout << "Before making circular: ";
    cout << (list.isCircular() ? "Circular\n" : "Not Circular\n");

    list.makeCircular();

    cout << "After making circular: ";
    cout << (list.isCircular() ? "Circular\n" : "Not Circular\n");

    return 0;
}

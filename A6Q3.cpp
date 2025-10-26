#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
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
        newNode->prev = temp;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
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

    int size() {
        if (last == nullptr)
            return 0;
        int count = 0;
        Node* temp = last->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != last->next);
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertLast(10);
    dll.insertLast(20);
    dll.insertLast(30);
    cout << "Size of Doubly Linked List: " << dll.size() << "\n";

    CircularLinkedList cll;
    cll.insertLast(5);
    cll.insertLast(15);
    cll.insertLast(25);
    cll.insertLast(35);
    cout << "Size of Circular Linked List: " << cll.size() << "\n";

    return 0;
}

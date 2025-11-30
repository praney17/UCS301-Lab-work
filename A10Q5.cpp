#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasLoop(Node* head) {
    unordered_set<Node*> visited;

    Node* curr = head;
    while (curr != nullptr) {
        if (visited.find(curr) != visited.end())
            return true;

        visited.insert(curr);
        curr = curr->next;
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->next->next->next->next = head->next;

    if (hasLoop(head))
        cout << "Linked list contains a loop.\n";
    else
        cout << "No loop found.\n";

    return 0;
}

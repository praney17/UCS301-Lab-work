#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

bool searchRecursive(Node* root, int value) {
    if (root == nullptr)
        return false;
    if (value == root->data)
        return true;
    if (value < root->data)
        return searchRecursive(root->left, value);
    else
        return searchRecursive(root->right, value);
}

bool searchNonRecursive(Node* root, int value) {
    while (root != nullptr) {
        if (value == root->data)
            return true;
        else if (value < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int MinElement(Node* root) {
    if (root == nullptr) return -1;
    while (root->left != nullptr)
        root = root->left;
    return root->data;
}

int MaxElement(Node* root) {
    if (root == nullptr) return -1;
    while (root->right != nullptr)
        root = root->right;
    return root->data;
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node* inorderSuccessor(Node* root, Node* target) {
    Node* successor = nullptr;

    if (target->right != nullptr)
        return findMin(target->right);

    while (root != nullptr) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (target->data > root->data)
            root = root->right;
        else
            break;
    }
    return successor;
}

Node* findMax(Node* root) {
    while (root && root->right != nullptr)
        root = root->right;
    return root;
}

Node* inorderPredecessor(Node* root, Node* target) {
    Node* predecessor = nullptr;

    if (target->left != nullptr)
        return findMax(target->left);

    while (root != nullptr) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else if (target->data < root->data)
            root = root->left;
        else
            break;
    }
    return predecessor;
}

int main() {

    Node* root = nullptr;
    root = insert(root, 30);
    root = insert(root, 55);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 11);

    int searchKey = 10;

    cout << "\n===== BST OPERATIONS =====\n\n";

    cout << "(a) Search (Recursive) for " << searchKey << ": ";
    cout << (searchRecursive(root, searchKey) ? "Found\n" : "Not Found\n");

    cout << "(a) Search (Non-Recursive) for " << searchKey << ": ";
    cout << (searchNonRecursive(root, searchKey) ? "Found\n" : "Not Found\n");

    cout << "(b) Maximum element of BST: " << MaxElement(root) << "\n";

    cout << "(c) Minimum element of BST: " << MinElement(root) << "\n";

    Node* target = root->left->right;  
    Node* succ = inorderSuccessor(root, target);
    cout << "(d) In-order Successor of " << target->data << ": ";
    cout << (succ ? to_string(succ->data) : "None") << "\n";

    Node* pred = inorderPredecessor(root, target);
    cout << "(e) In-order Predecessor of " << target->data << ": ";
    cout << (pred ? to_string(pred->data) : "None") << "\n";

    cout << "\n===========================\n";

    return 0;
}

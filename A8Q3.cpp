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

Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node* deleteNode(Node* curr, int key) {
    if (curr == nullptr)
        return curr;

    if (key < curr->data)
        curr->left = deleteNode(curr->left, key);

    else if (key > curr->data)
        curr->right = deleteNode(curr->right, key);

    else {
        if (curr->left == nullptr && curr->right == nullptr) {
            delete curr;
            return nullptr;
        }

        else if (curr->left == nullptr) {
            Node* succ = curr->right;
            delete curr;
            return succ;
        }
        else if (curr->right == nullptr) {
            Node* succ = curr->left;
            delete curr;
            return succ;
        }

        else {
            Node* temp = findMin(curr->right);
            curr->data = temp->data;
            curr->right = deleteNode(curr->right, temp->data);
        }
    }
    return curr;
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int maxDepth(Node* r) {
    if (r == nullptr)
        return 0;
    return 1 + max(maxDepth(r->left), maxDepth(r->right));
}

int minDepth(Node* r) {
    if (r == nullptr)
        return 0;

    if (r->left == nullptr)
        return 1 + minDepth(r->right);

    if (r->right == nullptr)
        return 1 + minDepth(r->left);

    return 1 + min(minDepth(r->left), minDepth(r->right));
}

int main() {
    Node* root = nullptr;

    root = insert(root, 30);
    root = insert(root, 55);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 11);
    root = insert(root, 75);
    root = insert(root, 45);

    cout << "\n===== BST OPERATIONS =====\n";

    cout << "\nInorder Traversal: ";
    inOrder(root);
    cout << "\n";

    cout << "Maximum Depth of BST: " << maxDepth(root) << "\n";

    cout << "Minimum Depth of BST: " << minDepth(root) << "\n";

    cout << "\nDeleting node 10...\n";
    root = deleteNode(root, 10);

    cout << "Inorder After Deletion: ";
    inOrder(root);
    cout << "\n";

    cout << "\n===========================\n";

    return 0;
}

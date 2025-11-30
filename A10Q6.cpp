#include <iostream>
#include <unordered_set>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool containsDuplicate(Node* root, unordered_set<int>& s) {
    if (root == nullptr)
        return false;

    if (s.find(root->data) != s.end())
        return true;

    s.insert(root->data);

    return containsDuplicate(root->left, s) || 
           containsDuplicate(root->right, s);
}

int main() {


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(2);

    unordered_set<int> seen;

    if (containsDuplicate(root, seen))
        cout << "Duplicates Found\n";
    else
        cout << "No Duplicates\n";

    return 0;
}

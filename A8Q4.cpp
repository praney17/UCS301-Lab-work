#include <iostream>
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
bool BSTUtil(Node* root, int minvalue, int maxvalue)
    {
        if(root == nullptr)
            return true;
        if((root->data > minvalue) && (root->data < maxvalue))
            return BSTUtil(root->left,minvalue,root->data) && BSTUtil(root->right,root->data,maxvalue);
        else
            return false;
    }

bool isBST(Node* root)
{
    return BSTUtil(root, -1000000,1000000);
}

int main()
{
    Node* n1 = new Node(20);
    n1->left = new Node(10);
    n1->right = new Node(30);
    n1->right->right = new Node(45);
    cout<<isBST(n1)<<endl;
}

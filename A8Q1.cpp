#include <iostream>
using namespace std;

struct Node{
int data;
Node* left;
Node* right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value)
{
    if(root == nullptr)
    {
        return new Node(value);
    }

    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void preOrder(Node* root)
{
    if(root == nullptr)
        return;
    cout<<' '<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root)
{
    if(root == nullptr)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<' '<<root->data;
}

void inOrder(Node* root)
{
    if(root == nullptr)
        return;
    inOrder(root->left);
    cout<<' '<<root->data;
    inOrder(root->right);
}

int main()
{
    Node* r1 = nullptr;
    r1 = insert(r1, 30);
    r1 = insert(r1, 55);
    r1 = insert(r1, 9);
    r1 = insert(r1, 7);
    r1 = insert(r1, 10);
    r1 = insert(r1, 11);
    cout<<"Preorder: ";
    preOrder(r1);
    cout<<endl<<"Postorder: ";
    postOrder(r1);
    cout<<endl<<"Inorder: ";
    inOrder(r1);
    cout<<endl;
}

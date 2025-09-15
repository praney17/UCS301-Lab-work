#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) 
	{
        data = val;
        next = NULL;
    }
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() 
	{
        head = NULL;
    }

    void insert(int val) 
	{
        Node* newnode = new Node(val);
        if(head == NULL) 
		{
            head = newnode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) 
		{
            temp = temp->next;
        }
        temp->next = newnode;
    }
	
	void reverse() {
		Node* prev = NULL;
		Node* curr = head;
        Node* next = NULL; 
		while(curr != NULL) 
		{
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
        }
		
		head = prev;
	}
	
	void display() {
        if(head == NULL) 
		{
            cout<<"Empty List";
            return;
        }
        Node* temp = head;
        while(temp != NULL) 
		{
            cout<<temp->data;
            if (temp->next != NULL) 
				cout << "->";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    SinglyLinkedList obj;
    int n, x;
	cout<<"\nEnter no. of nodes : ";
	cin>>n;
	
	cout<<"\nEnter node values : \n";
	for(int i = 0; i < n; i++) 
	{
		cin>>x;
    	obj.insert(x);
	}

    obj.reverse();
    
    cout<<"\nReversed Linked List : \n";
	obj.display();

    return 0;
}

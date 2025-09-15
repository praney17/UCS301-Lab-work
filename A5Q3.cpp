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
	
	void findMiddle() {
		Node* temp1 = head;
		Node* temp2 = head;
        Node* temp3 = NULL; 
		while(temp1 != NULL && temp1->next != NULL) 
		{
			temp3 = temp2;
            temp2 = temp2->next;
            temp1 = temp1->next->next;
        }
		
		if(temp1 == NULL)
		{
			cout<<"\nMiddle = "<<temp3->data <<" and "<<temp2->data;
		}
		else
			cout<<"\nMiddle = "<<temp2->data;
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

    obj.findMiddle();

    return 0;
}

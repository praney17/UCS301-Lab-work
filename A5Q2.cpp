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

    int deleteAllOccurrences(int key) 
	{
        int count = 0;
        while (head != NULL && head->data == key) 
		{
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        Node* curr = head;
        Node* prev = NULL;

        while(curr != NULL) 
		{
            if(curr->data == key) 
			{
                Node* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
                count++;
            } 
			else 
			{
                prev = curr;
                curr = curr->next;
            }
        }
        return count;
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

    int key;
    cout<<"\nEnter key : ";
    cin>>key;
    cout << "Original List: ";
    obj.display();

    int count = obj.deleteAllOccurrences(key);

    cout<<"Count: "<<count<<endl;
    cout<<"Updated List: ";
    obj.display();

    return 0;
}

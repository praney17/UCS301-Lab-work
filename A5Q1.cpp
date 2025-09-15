#include<iostream>
using namespace std;
struct node
{
	int info;
	struct node *next;
};

class SinglyLinkedList
{
	struct node *head;
	public:
		SinglyLinkedList()
		{
			head=NULL;
		}
		struct node* createNode()
		{
			struct node *mynode = new node;
			if(mynode==NULL)
			{
				cout<<"\nOverflow";
			}
			else
			{
				cout<<"Enter Information : ";
				cin>>mynode->info;
				mynode->next=NULL;
			}
			return mynode;
		}
		
		void insertion_at_beg()
		{
			struct node *newnode = createNode();
			if(head==NULL)
			{
				head = newnode;
			}
			else
			{
				newnode->next = head;
				head = newnode;
			}
			cout<<"\nNew Node "<<newnode->info<<" added at beg of list\n";
		}
		void insertion_at_end()
		{
			struct node *newnode = createNode();
			if(head==NULL)
			{
				head = newnode;
			}
			else
			{
				struct node *temp1;
				
				temp1 = head;
				
				while(temp1->next!=NULL)
				{
					temp1 = temp1->next;
				}
				temp1->next = newnode;
			}
			cout<<"\nNew Node "<<newnode->info<<" added at end of list\n";
		}
		void deletion_at_beg()
		{
			if(head==NULL)
			{
				cout<<"\nUnderflow\n";
				return;
			}
			
			struct node *temp1;
			temp1 = head;
			head = temp1->next;
			
			cout<<"\nElement "<<temp1->info<<" Deleted from beg\n";
			delete temp1;
		}
		void deletion_at_end()
		{
			if(head==NULL)
			{
				cout<<"\nUnderflow\n";
				return;
			}
			
			struct node *temp1, *temp2;
			temp2 = NULL;
			temp1 = head;
			while(temp1->next!=NULL)
			{
				temp2 = temp1;
				temp1 = temp1->next;
			}
			if(temp2==NULL)
			{
				head=NULL;
			}
			else
			{
				temp2->next=NULL;
			}
			cout<<"\nElement "<<temp1->info<<" Deleted from end\n";
			delete temp1;
		}
		
		int get_length()
		{
			int count=0;
			struct node *temp = head;
			while(temp!=NULL)
			{
				count++;
				temp = temp->next;
			}
			return count;
		}
		
		void deletion_at_loc()
		{
		    if (head == NULL) {
		        cout<<"\nUnderflow\n";
		        return;
		    }
		
		    int val;
		    cout<<"Enter Value Of Node To Be Deleted : ";
		    cin>>val;
		
		    struct node *temp1 = head, *temp2 = NULL;
		
		    while(temp1 != NULL && temp1->info != val)
		    {
		        temp2 = temp1;
		        temp1 = temp1->next;
		    }
		
		    if(temp1 == NULL) {
		        cout<<"\nNode Not Found!\n";
		        return;
		    }
		
		    if(temp2 == NULL) 
			{
		        head = head->next;
		    } 
			else 
			{
		        temp2->next = temp1->next;
		    }
		
		    cout<<"\nElement "<<temp1->info<<" Deleted successfully\n";
		    delete temp1;
		}

		
		void insertion_at_loc()
		{
		    int val;
		    cout<<"Insert node after (value) : ";
		    cin>>val;
		
		    struct node *temp1 = head;
		    while(temp1 != NULL && temp1->info != val) 
		    {
		        temp1 = temp1->next;
		    }
		    if(temp1 == NULL) 
		    {
		        cout << "\nNode Not Found!\n";
		        return;
		    }
		
		    struct node *newnode = createNode();
		    newnode->next = temp1->next;
		    temp1->next = newnode;
		
		    cout<<"\nElement "<<newnode->info<<" Inserted successfully after node with value "<<val<<"\n"; 
		}

		void searching()
		{
			int i=1, flag=0, el;
			cout<<"\nEnter Element To Search : ";
			cin>>el;
			
			struct node *temp1 = head;
			while(temp1 != NULL)
			{
				if(temp1->info==el)
				{
					cout<<"\nElement found : "<<i;
					flag=1; 
					break;
				}
				i++;
				temp1 = temp1->next;
			}
			if(flag==0)
			{
				cout<<"\nNot Found";
			}
		}
		
		void traversing()
		{
			if(head == NULL)
			{
				cout<<"\nUnderflow";
				return;
			}
			
			cout<<"\n----Singly Linked List----\n";
			
			struct node *temp = head;
			while(temp!=NULL)
			{
				cout<<temp->info;
				if(temp->next != NULL)
					cout<<"	->	";
				temp = temp->next;
			}
			cout<<endl;
		}
};

int main()
{
	SinglyLinkedList obj;
	int ch;
	while(1)
	{
		cout<<"\n1. Insertion At Beginning";
		cout<<"\n2. Insertion At End";
		cout<<"\n3. Insertion At Loc";
		cout<<"\n4. Deletion At Beg";
		cout<<"\n5. Deletion At End";
		cout<<"\n6. Deletion At Loc";
		cout<<"\n7. Searching";
		cout<<"\n8. Traversing";
		cout<<"\n9. Exit";
		cout<<"\nEnter Choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				obj.insertion_at_beg();
				break;
			case 2:
				obj.insertion_at_end();
				break;
			case 3:
				obj.insertion_at_loc();
				break;
			case 4:
				obj.deletion_at_beg();
				break;
			case 5:
				obj.deletion_at_end();
				break;
			case 6:
				obj.deletion_at_loc();
				break;
			case 7:
				obj.searching();
				break;
			case 8:
				obj.traversing();
				break;
			case 9:
				cout<<"\nExiting...\n";
				return 0;
			default:
				cout<<"Invalid";
				break;
		}
	}
	return 0;
}
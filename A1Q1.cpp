#include <iostream>
using namespace std;
const int ok = 100; 


void create(int arr[],int n){
    if (n>ok){
        cout<<"overflow";
        return;
    }
    cout<<"enter the elements of the array: ";
    for (int i=0; i< n;i++){
        cin>>arr[i];
    }

}

void display(int arr[], int n){
    cout<<"The array is: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    

}
void insert(int arr[], int &n){
    int index, ele;
    cout<<"At what position do you wanna add the element: ";
    cin>>index;
    cout<<"what element do you wanna add: ";
    cin>>ele;
    for(int i=n;i>index;i--){
        arr[i]=arr[i-1];
    }
    arr[index]=ele;
    n=n+1;



}

void Delete(int arr[], int &n){
    int index;
    cout<<"At what position do you wanna delete: ";
    cin>>index;
    for(int i=index;i<n;i++){
        arr[i]=arr[i+1];
    }
    n=n-1;

}


void linear_search(int arr[],int n){
    int key;
    cout<<"What element do you wanna find: ";
    cin>>key;
    for(int i=0;i<n;i++)
    {
        if (arr[i]==key){
            cout<<key<<" found at index "<<i;
            return;
        }
    }

    cout<<key<<" not found in the array";


}

int main(){
    int arr[ok];
    int choice;
    int n;
    while (true){
        cout<<"How many elements do you want in the array: ";
        cin>>n;
        if (n>0 && n<ok){
            break;
        }
        else {
            cout<<"please enter again\n";
        }
    }

    while (true) {
        cout<<"\n-----MENU-----\n";
        cout<<"1.) CREATE\n";
        cout<<"2.) DISPLAY\n";
        cout<<"3.) INSERT\n";
        cout<<"4.) DELETE\n";
        cout<<"5.) LINEAR SEARCH\n";
        cout<<"6.) EXIT\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice){
            case 1: create(arr,n); break;
            case 2: display(arr,n); break;
            case 3: insert(arr,n); break;
            case 4: Delete(arr,n); break;
            case 5: linear_search(arr,n); break;
            case 6: cout<<"Exiting the Program\n"; return 0;
            default: cout<<"Invalid choice! Try again\n";
        }
    }
    return 0;
}
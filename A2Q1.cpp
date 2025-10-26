#include <iostream>
using namespace std;

int main(){
    int n,i,l,r,p;
    int found=-1;
    cout<<"how big do you want the array to be: \n";
    cin>>n;
    int arr[n];
    l=0;
    r=n-1;
    cout<<"Enter your sorted array: \n";
    for (i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"what element do you wanna add: ";
    cin>>key;
    while (l<=r){
        p=(l+r)/2;
        if (arr[p]==key){
            found=p;
            break;
        }
        if(arr[p]<key){
            l=p+1;
        }
        else{
            r=p-1;
        }    
    }
    if(found!=-1){
        cout<<"The element was found at "<<found;
    }
    else{
        cout<<"Element not found";
    }
    return 0;
}
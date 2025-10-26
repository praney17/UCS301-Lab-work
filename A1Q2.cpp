#include <iostream>
using namespace std;

int main() {
   // n3 time complexity, idk how to fix it
   int n;
   int arr[100];
   cout<<"Enter the number of elements: ";
   cin>>n;
   cout<<"Enter the elements of the array: ";
   for (int i=0; i<n;i++){
    cin>>arr[i];
   }

   for (int i=0; i<n;i++){
    for (int j=i+1; j<n ; ){
        if ( arr[j] == arr[i] ){
            for ( int k = j ; k < n-1 ; k++){
                arr[k] = arr[k+1];
            }
            n--;
        } 
        else{
            j++;
        }
    }
   }

   cout<<"Array after removing duplicates: \n";
   for (int i=0; i<n; i++){
    cout<<arr[i]<<" ";
   }


   


   return 0;
}
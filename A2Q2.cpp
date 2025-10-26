#include <iostream>
using namespace std;

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    int temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if (arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
 
}

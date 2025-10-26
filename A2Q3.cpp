#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;  
        }
    }
   
    return n;
}

int findMissingBinary(int arr[], int n) {
    int left = 0, right = n - 2; 

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left + 1;
}

int main() {
    int n;
    cout << "Enter value of n (range 1..n): ";
    cin >> n;

    
    int arr[n - 1];
    cout << "Enter " << n - 1 << " elements in sorted order:\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << "\nChoose method:\n";
    cout << "1. Linear Search (O(n))\n";
    cout << "2. Binary Search (O(log n))\n";
    int choice;
    cin >> choice;

    int missing; 
    if (choice == 1) {
        missing = findMissingLinear(arr, n);
    } else if (choice == 2) {
        missing = findMissingBinary(arr, n);
    } else {
        cout << "Invalid choice!" << endl; 
    }

   
    cout << "Missing number is: " << missing << endl;

    return 0;
}

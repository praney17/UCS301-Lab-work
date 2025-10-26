#include <iostream>
using namespace std;

int countInversionsBrute(int A[], int n) {
    int count = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (A[i] > A[j]) count++;
        }
    }
    return count;
}

int mergeAndCount(int A[], int temp[], int left, int mid, int right) {
    int i = left, j = mid, k = left, invCount = 0;
    while (i < mid && j <= right) {
        if (A[i] <= A[j]) temp[k++] = A[i++];
        else {
            temp[k++] = A[j++];
            invCount += (mid - i);
        }
    }
    while (i < mid) temp[k++] = A[i++];
    while (j <= right) temp[k++] = A[j++];
    for (i = left; i <= right; i++) A[i] = temp[i];
    return invCount;
}

int mergeSortAndCount(int A[], int temp[], int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        invCount += mergeSortAndCount(A, temp, left, mid);
        invCount += mergeSortAndCount(A, temp, mid+1, right);
        invCount += mergeAndCount(A, temp, left, mid+1, right);
    }
    return invCount;
}

int main() {
    int n, choice;
    int A[100], B[100], temp[100];
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    while (true) {
        cout << "\n1. Brute Force\n2. Efficient O(n log n)\n3. Exit\nChoice: ";
        cin >> choice;
        if (choice == 3) break;
        if (choice == 1) cout << "Inversions: " << countInversionsBrute(A, n) << endl;
        else if (choice == 2) {
            for (int i = 0; i < n; i++) B[i] = A[i];
            cout << "Inversions: " << mergeSortAndCount(B, temp, 0, n-1) << endl;
        }
    }
    return 0;
}

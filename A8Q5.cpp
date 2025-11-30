#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left  = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left  = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}


void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void buildMinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void heapSortMax(int arr[], int n) {
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void heapSortMin(int arr[], int n) {
    buildMinHeap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        minHeapify(arr, i, 0);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {

    int arr[9] = {40, 30, 35, 36, 12, 70, 80, 7, 8};
    int n = 9;

    int maxArr[9], minArr[9], sortedMax[9], sortedMin[9];
    copy(arr, arr + n, maxArr);
    copy(arr, arr + n, minArr);
    copy(arr, arr + n, sortedMax);
    copy(arr, arr + n, sortedMin);

    cout << "\nOriginal Array: ";
    printArr(arr, n);

    cout << "\n--- MAX HEAP ---\n";
    buildMaxHeap(maxArr, n);
    cout << "Max Heap: ";
    printArr(maxArr, n);

    cout << "\n--- MIN HEAP ---\n";
    buildMinHeap(minArr, n);
    cout << "Min Heap: ";
    printArr(minArr, n);

    cout << "\n--- HEAP SORT USING MAX HEAP (Ascending Order) ---\n";
    heapSortMax(sortedMax, n);
    cout << "Sorted: ";
    printArr(sortedMax, n);

    cout << "\n--- HEAP SORT USING MIN HEAP (Descending Order) ---\n";
    heapSortMin(sortedMin, n);
    cout << "Sorted: ";
    printArr(sortedMin, n);

    cout << endl;
    return 0;
}

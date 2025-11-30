#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        int parent = (index - 1) / 2;

        if (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int getMax() {
        if (heap.empty()) {
            cout << "Priority queue is empty\n";
            return -1;
        }
        return heap[0];
    }

    int extractMax() {
        if (heap.empty()) {
            cout << "Priority queue is empty\n";
            return -1;
        }

        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown(0);

        return maxValue;
    }

    int size() {
        return heap.size();
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(40);
    pq.insert(10);
    pq.insert(50);
    pq.insert(20);

    cout << "Max: " << pq.getMax() << endl;

    cout << "Extracted: " << pq.extractMax() << endl;
    cout << "New Max: " << pq.getMax() << endl;

    return 0;
}

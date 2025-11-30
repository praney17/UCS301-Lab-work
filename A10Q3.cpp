#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    cout << "\nFrequencies of each number:\n";
    for (auto &p : freq) {
        cout << p.first << " → " << p.second << "\n";
    }

    return 0;
}

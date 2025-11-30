#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> freq;

    for (int x : arr)
        freq[x]++;

    for (int x : arr) {
        if (freq[x] == 1) {
            cout << "First non-repeating element: " << x << endl;
            return 0;
        }
    }

    cout << "No non-repeating element found.\n";
    return 0;
}

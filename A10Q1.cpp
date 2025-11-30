#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_set<int> s;

    bool duplicateFound = false;

    for (int i = 0; i < n; i++) {
        if (s.find(arr[i]) != s.end()) {
            duplicateFound = true;
            break;
        }
        s.insert(arr[i]);
    }

    if (duplicateFound)
        cout << "Array contains duplicates.\n";
    else
        cout << "Array does NOT contain duplicates.\n";

    return 0;
}

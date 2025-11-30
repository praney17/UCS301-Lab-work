#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int n1, n2;

    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> arr1(n1);

    cout << "Enter elements of first array:\n";
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> arr2(n2);

    cout << "Enter elements of second array:\n";
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    unordered_set<int> s;
    vector<int> common;

    for (int x : arr1)
        s.insert(x);

    for (int x : arr2) {
        if (s.find(x) != s.end()) {
            common.push_back(x);
            s.erase(x);
        }
    }

    cout << "\nCommon elements:\n";
    if (common.empty()) {
        cout << "No common elements.\n";
    } else {
        for (int x : common)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}

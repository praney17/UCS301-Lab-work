#include <iostream>
using namespace std;

int main() {
    int n, A[100];
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    int distinct = 0;
    for (int i = 0; i < n; i++) {
        bool seen = false;
        for (int j = 0; j < i; j++) {
            if (A[i] == A[j]) {
                seen = true;
                break;
            }
        }
        if (!seen) distinct++;
    }

    cout << "Total distinct elements: " << distinct << endl;
    return 0;
}

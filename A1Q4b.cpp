#include <iostream>
using namespace std;

int main(){
    int r1, c1, r2, c2;
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible. Columns of first matrix must equal rows of second matrix." << endl;
    } else {
        int a[100][100], b[100][100], result[100][100] = {0};

        cout << "Enter elements of first matrix:" << endl;
        for (int i = 0; i < r1; ++i)
            for (int j = 0; j < c1; ++j){
                cin >> a[i][j];
            }

        cout << "Enter elements of second matrix:" << endl;
        for (int i = 0; i < r2; ++i)
            for (int j = 0; j < c2; ++j){
                cin >> b[i][j];
            }


        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j) {
                for (int k = 0; k < c1; ++k) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        cout << "Resultant matrix:" << endl;
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j) {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
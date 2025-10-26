#include <iostream>
using namespace std;

void diagonalMatrix(int n) {
    int diag[100];
    cout << "Enter " << n << " diagonal elements: ";
    for (int i = 0; i < n; i++) cin >> diag[i];
    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

void triDiagonalMatrix(int n) {
    int tri[300];
    cout << "Enter " << 3*n - 2 << " elements (lower, main, upper): ";
    for (int i = 0; i < 3*n - 2; i++) cin >> tri[i];
    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << tri[n-1 + i] << " ";
            else if (i == j+1) cout << tri[i-1] << " ";
            else if (j == i+1) cout << tri[2*n-1 + i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

void lowerTriangularMatrix(int n) {
    int size = n*(n+1)/2;
    int lower[1000];
    cout << "Enter " << size << " elements (row-wise): ";
    for (int i = 0; i < size; i++) cin >> lower[i];
    cout << "Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) cout << lower[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

void upperTriangularMatrix(int n) {
    int size = n*(n+1)/2;
    int upper[1000];
    cout << "Enter " << size << " elements (row-wise): ";
    for (int i = 0; i < size; i++) cin >> upper[i];
    cout << "Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) cout << upper[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

void symmetricMatrix(int n) {
    int size = n*(n+1)/2;
    int sym[1000];
    cout << "Enter " << size << " elements (lower triangle): ";
    for (int i = 0; i < size; i++) cin >> sym[i];
    cout << "Matrix:\n";
    int k = 0;
    int mat[100][100] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            mat[i][j] = sym[k++];
            mat[j][i] = mat[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, n;
    while (true) {
        cout << "\n--- Special Matrices Menu ---\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tri-diagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 6) break;
        cout << "Enter size of matrix (n x n): ";
        cin >> n;
        switch (choice) {
            case 1: diagonalMatrix(n); break;
            case 2: triDiagonalMatrix(n); break;
            case 3: lowerTriangularMatrix(n); break;
            case 4: upperTriangularMatrix(n); break;
            case 5: symmetricMatrix(n); break;
            default: cout << "Invalid choice!\n";
        }
    }
    return 0;
}

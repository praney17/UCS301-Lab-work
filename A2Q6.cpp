#include <iostream>
using namespace std;

void readSparse(int A[][3], int &n) {
    cout << "Enter number of non-zero elements: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];  // row col value
    }
}

void printSparse(int A[][3], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i][0] << " " << A[i][1] << " " << A[i][2] << endl;
    }
}

void transpose(int A[][3], int B[][3], int n) {
    for (int i = 0; i < n; i++) {
        B[i][0] = A[i][1];
        B[i][1] = A[i][0];
        B[i][2] = A[i][2];
    }
    printSparse(B, n);
}

void addSparse(int A[][3], int n1, int B[][3], int n2, int C[][3], int &n3) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        } else if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2];
            i++; k++;
        } else {
            C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2];
            j++; k++;
        }
    }
    while (i < n1) { C[k][0]=A[i][0]; C[k][1]=A[i][1]; C[k][2]=A[i][2]; i++; k++; }
    while (j < n2) { C[k][0]=B[j][0]; C[k][1]=B[j][1]; C[k][2]=B[j][2]; j++; k++; }
    n3 = k;
    printSparse(C, n3);
}

void multiplySparse(int A[][3], int n1, int B[][3], int n2, int C[][3], int &n3, int rowsA, int colsA, int colsB) {
    n3 = 0;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            int sum = 0;
            for (int k = 0; k < n1; k++) {
                if (A[k][0] == i) {
                    for (int l = 0; l < n2; l++) {
                        if (B[l][0] == A[k][1] && B[l][1] == j) {
                            sum += A[k][2] * B[l][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                C[n3][0] = i;
                C[n3][1] = j;
                C[n3][2] = sum;
                n3++;
            }
        }
    }
    printSparse(C, n3);
}

int main() {
    int A[100][3], B[100][3], C[200][3];
    int n1, n2, n3;
    int rowsA, colsA, rowsB, colsB, choice;

    while (true) {
        cout << "\n1. Transpose\n2. Addition\n3. Multiplication\n4. Exit\nChoice: ";
        cin >> choice;
        if (choice == 4) break;

        if (choice == 1) {
            cout << "Enter rows cols: "; cin >> rowsA >> colsA;
            readSparse(A, n1);
            transpose(A, B, n1);
        }
        else if (choice == 2) {
            cout << "Enter rows cols: "; cin >> rowsA >> colsA;
            readSparse(A, n1);
            readSparse(B, n2);
            addSparse(A, n1, B, n2, C, n3);
        }
        else if (choice == 3) {
            cout << "Enter rows cols of first matrix: "; cin >> rowsA >> colsA;
            readSparse(A, n1);
            cout << "Enter rows cols of second matrix: "; cin >> rowsB >> colsB;
            if (colsA != rowsB) { cout << "Not possible\n"; continue; }
            readSparse(B, n2);
            multiplySparse(A, n1, B, n2, C, n3, rowsA, colsA, colsB);
        }
    }
    return 0;
}

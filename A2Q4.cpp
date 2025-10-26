#include <iostream>
#include <string>
using namespace std;

void concatenateStrings() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    cout << "Concatenated String: " << s1 + s2 << endl;
}

void reverseString() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }

    cout << "Reversed String: " << s << endl;
}

void deleteVowels() {
    string s, res = "";
    cout << "Enter a string: ";
    cin >> s;

    for (char c : s) {
        char l = (c >= 'A' && c <= 'Z') ? c + 32 : c; // manual tolower
        if (!(l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')) {
            res += c;
        }
    }

    cout << "String after removing vowels: " << res << endl;
}

void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    string arr[100];
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}

void toLowerCase() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
    }
    cout << "Lowercase character: " << ch << endl;
}

int main() {
    int choice;
    while (true) {
        cout << "\n--- String Programs Menu ---\n";
        cout << "1. Concatenate Strings\n";
        cout << "2. Reverse a String\n";
        cout << "3. Delete Vowels from String\n";
        cout << "4. Sort Strings Alphabetically\n";
        cout << "5. Convert Uppercase to Lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: concatenateStrings(); break;
            case 2: reverseString(); break;
            case 3: deleteVowels(); break;
            case 4: sortStrings(); break;
            case 5: toLowerCase(); break;
            case 6: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}

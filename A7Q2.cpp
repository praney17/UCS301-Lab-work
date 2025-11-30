#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int minIndex = left;
        int maxIndex = left;

        for (int i = left; i <= right; i++)
        {
            if (arr[i] < arr[minIndex])
                minIndex = i;

            if (arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        swap(arr[left], arr[minIndex]);

        if (maxIndex == left)
            maxIndex = minIndex;

        swap(arr[right], arr[maxIndex]);

        left++;
        right--;
    }
}

int main()
{
    int arr[] = {3, 1, 6, 2, 10, 14, 6, 3, 99, 100, 32, 43};
    int n = sizeof(arr) / sizeof(arr[0]);

    improvedSelectionSort(arr, n);

    cout << "Improved Selection Sort: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}

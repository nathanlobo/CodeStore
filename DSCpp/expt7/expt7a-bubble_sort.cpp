// C++ program to implement Bubble Sort algorithm on the given array

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no swaps happened, array is already sorted
        if (!swapped)
            break;
    }
}
int main() {
    int arr[] = {5, 2, 9, 1, 5, 6,12,0,25,20,16};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << n;
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    bubbleSort(arr, n);
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
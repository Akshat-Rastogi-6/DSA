#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {7, 4, 10, 8, 3, 1};
    int n = 6;

    insertionSort(arr, n);

    cout << "Sorted array: ";
    for (int h = 0; h < n; h++) {
        cout << arr[h] << " ";
    }

    return 0;
}

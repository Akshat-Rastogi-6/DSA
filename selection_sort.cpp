#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(arr[i], arr[min]);
        }
    }

    for (int h = 0; h < n; h++) {
        cout << arr[h] << " ";
    }
}

int main() {
    int arr[] = {7, 4, 10, 8, 3, 1,100,78,23,69,53,94,14,58};
    int n = 14;

    sort(arr, n);

    return 0;
}

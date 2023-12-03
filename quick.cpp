#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void quicksort(int arr[], int low, int high){
    if(low<high){
        int pivotindex = partition(arr, low, high);
        quicksort(arr, low, pivotindex - 1);
        quicksort(arr, pivotindex + 1, high);
    }
}

int main() {
    int arr[] = {11, 25, 9, 8, 14, 33, 100, 65, 88, 29, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quicksort(arr, 0, size - 1);

    cout << "After Sorting: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
#include<iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1];
    int R[n2];

    for(int i = 0; i<n1 ; i++){
        L[i] = arr[left + i];
    }

    for(int i = 0; i<n2 ; i++){
        R[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k++] = L[i++];
        }
        else{
            arr[k++] = R[j++];
        }
    }

    while(i<n1){
        arr[k++] = L[i++];
    }

    while(j<n2){
        arr[k++] = R[j++];
    }
}

void mergesort(int arr[], int left, int right){
    if(left<right){
        int mid = left + (right - left) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+ 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int arr[] = {11, 5, 26, 98, 10, 51, 6};

    int size = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr, 0, size - 1);

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
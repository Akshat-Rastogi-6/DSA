#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for(int i = 0; i<n1; i++){
        L[i] = arr[l + i];
    }

    for(int i = 0; i<n2; i++){
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while(i<n1 && j <n2){
        if(L[i] <= R[j]){
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

void mergesort(int arr[], int l, int r){
    if(l<r){
        int mid = l + (r - l) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main(){
    int arr[] = {11, 5, 26, 98, 10, 51, 6};
    int arrsize = sizeof(arr)/sizeof(arr[0]);

    mergesort(arr, 0, arrsize-1);

    for (int i = 0; i < arrsize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
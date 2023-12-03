#include<iostream>
using namespace std;

void push(int arr[10], int a, int &top){
    if(top<10){
        arr[top++] = a;
    }else{
        cout<<"Stack is full"<<endl;
    }
}

void pop(int arr[10], int &top){
    if(top>0){
        cout<<arr[--top]<<" popped."<<endl;
    }
    else{
        cout<<"Stack Empty."<<endl;
    }
}

void display(int arr[10], int &top){
    cout<<"The Content of the STACK are: ";
    for(int i = 0; i<top; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[9];
    int top = 0;
    push(arr, 10, top);
    push(arr, 20, top);
    push(arr, 30, top);
    push(arr, 40, top);
    push(arr, 50, top);
    push(arr, 60, top);

    pop(arr, top);

    display(arr, top);
}
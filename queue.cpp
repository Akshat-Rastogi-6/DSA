#include<iostream>
using namespace std;

void enqueue(int arr[10], int a, int &top, int &rear){
    if(top == -1 && rear == -1){
        arr[++rear] = a;
        top = rear;
    }
    else if(rear >= 0 && rear < 9){
        arr[++rear] = a;
    }
    else{
        cout << "Queue is full" << endl;
    }
}

void dequeue(int arr[10], int &top, int &rear){
    if(rear>=top){
        cout << arr[top++] << " is dequeued" << endl;
    }
    else{
        cout << "Empty QUEUE" << endl;
    }
}

void display(int arr[10], int &top, int &rear){
    cout << "The content of the QUEUE : ";
    for(int i = top; i <= rear; i++){
        cout << arr[i] << " ";
    }
}

void peek(int arr[10], int &top){
    cout<<arr[top-1];
}

int main(){
    int arr[10];
    int top = -1; // Initialize top to 0
    int rear = -1;

    enqueue(arr, 10, top, rear);
    enqueue(arr, 20, top, rear);
    enqueue(arr, 30, top, rear);
    enqueue(arr, 40, top, rear);
    enqueue(arr, 50, top, rear);
    enqueue(arr, 60, top, rear);

    dequeue(arr, top, rear);

    cout<< top<< " "<< rear<<endl;

    display(arr, top, rear);

    return 0;
}

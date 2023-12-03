#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = nullptr;
node* tail = nullptr;

void enqueue(int a) {
    node* newnode = new node;
    newnode->data = a;
    newnode->next = nullptr;
    
    if (tail == nullptr) {
        head = tail = newnode;
    }
    else {
        tail->next = newnode;
        tail = newnode;
    }
}

void dequeue() {
    if (head == nullptr) {
        cout << "Queue is empty" << endl;
        return;
    }

    node* temp = head;
    head = head->next;
    delete temp;
    
    if (head == nullptr) {
        tail = nullptr; // Update the tail when the last element is dequeued
    }
}

void display() {
    node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    dequeue();

    display();

    return 0;
}

#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head = nullptr;

void insert(int a){
    node* newnode = new node;
    newnode->data = a;
    newnode->next = nullptr;

    if(head==nullptr){
        head = newnode;
        head->next = head;
    }
    else{
        node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        tail->next = newnode;
        newnode->next = head;
    }
}

void display(){
    node* tail = head;
    do{
        cout<<tail->data<<" "; 
        tail = tail->next;
    }
    while(tail != head);
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(50);
    insert(60);

    display();
}
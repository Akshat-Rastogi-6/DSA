#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* head= nullptr;

void push(int a){
    node* newnode = new node;
    newnode->data = a;
    newnode->next = head;    
    head = newnode;
}

void display(){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void pop(){
    if(head==nullptr){
        cout<<" Empty Stack";
    }
    else{
        node* temp = head;
        head = head->next;
        delete temp;
    }
}

void peek(){
    if(head==nullptr){
        cout<<"empty Stack";
    }
    else{
        int temp = head->data;
        cout<<temp<<endl;
    }
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    peek();
    pop();

    pop();
    peek();

    pop();
    peek();

    pop();
    peek();

    pop();
    peek();

    display();
}
#include<iostream>
using namespace std;

struct node {
    int data;
    node *next ;
}*head = NULL;

void insert(int a) {
    node* newnode = new node;
    newnode->data = a;
    newnode->next = nullptr;

    if(head==nullptr) {
        head = newnode;
    }

    else {
        node* temp = head;
        while(temp->next!=nullptr) {
            temp=temp->next;
        }
        temp->next = newnode;
    }
}

void display() {
    node* temp = head;
    while(temp) {
        cout<<temp->data<<" ";
        temp = temp->next;
    };
    cout<<endl;
}

void deleted(int a) {
    node* nex = head;
    node* prev;

    while(nex && nex->data != a){
        prev = nex;
        nex = nex->next;
    }

    prev->next = nex->next;
    
}

int main() {

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    deleted(40);

    display();

    return 0;
}
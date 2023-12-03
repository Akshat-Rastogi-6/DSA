#include <iostream>
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

    if(head == nullptr){
        head = newnode;
    }

    else{
        node* temp = head;
        while(temp){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insert_start(int a){
    node* newnode = new node;
    newnode->data = a;
    newnode->next = head;
    head = newnode;
}

void insert_position(int a, int pos){
    node* newnode = new node;
    newnode->data = a;

    if(pos == 0){
        newnode->next = head;
        head = newnode;
        return;
    }

    node* temp = head;
    int i = 0;

    while(i < pos-1 && temp!= nullptr){
        temp = temp->next;
        i++;
    }

    if(temp->next == nullptr){
        temp->next = newnode;
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void del_start(){
    node* temp = head;
    if(temp==nullptr){
        return;
    }

    head = temp->next;
    delete temp;
}

void del_end(){
    if(head == nullptr){
        return;
    }

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    node* temp = head;
    node* current = nullptr;
    while(temp->next!=nullptr){
        current = temp;
        temp = temp->next;
    }

    current->next = nullptr;
    delete temp;
}

void del_pos(int pos){
    node* temp = head;
    node* current = nullptr;

    if(pos == 1){
        del_start();
    }

    else{
        int i = 0;
        while(i < pos-1 && temp!= nullptr){
            current = temp;
            temp = temp->next;
            i++;
        }

        current->next = temp->next;
        temp->next = nullptr;
        delete temp;
    }
}

void search(int a){
    node* temp = head;
    int c = 1;
    while(temp->next!=nullptr){
        if(temp->data == a){
            cout<<"Data found at: "<<c<<endl;
            return;
        }
        c++;
        temp = temp->next;
    }
}

void display(){
    node * temp = head;
        while (temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
}

int main(){
    insert(10);
    insert(20);
    insert(30);
    insert(50);
    insert(60);
    insert(70);
    insert(80);
    insert_start(0);

    display();
}
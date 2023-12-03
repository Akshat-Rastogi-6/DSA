// create a doubly linked list
// inser values
#include<iostream>
using namespace std;
struct node{
    node *prev;
    int data;
    node *next;
};

node* head = nullptr;
node* tail = nullptr;

void insert_right(int a) {
    node* newnode = new node;
    newnode->data = a;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    if (head == nullptr) {
        head = newnode;
        tail = head;
    } else {
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
        tail = newnode;
    }
}

void insert_left(int a) {
    node* newnode = new node;
    newnode->data = a;
    newnode->next = head;
    newnode->prev = nullptr;

    if (head == nullptr) {
        head = newnode;
        tail = head;
    } else {
        head->prev = newnode;
        head = newnode;
    }
}

void display(){
    node* current = head;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

void del(int a){
    node* temp = head;
    node* tmp2;
    while(temp->data != a){
        tmp2 = temp;
        temp = temp->next;
    }

    tmp2->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}

void display_rev(){
    node* current = tail;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current = current->prev;
    }
    cout<<endl;
}

int main(){
    insert_right(10);
    insert_right(20);
    insert_right(30);
    insert_left(35);
    insert_left(45);
    insert_left(55);
    insert_right(40);
    insert_right(50);
    insert_right(60);
    insert_right(70);

    del(45);

    display();
    display_rev();
}

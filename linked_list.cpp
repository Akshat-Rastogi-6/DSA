#include<iostream>
using namespace std;
// operations to be performed
// insert at the start
// insert at the end
// insert at a position
// deletion from starting
// deletion from ending
// deletion from any position
// search
// traversal
// get length
// empty check
// reverse

struct node{
    int data;
    node* next;
};
node *head = nullptr;

void insert(int a){
    node* newnode = new node;
    newnode->data = a;
    newnode->next = nullptr;
    if(head==nullptr){
        head = newnode;
    }
    else{
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insert_start(int a){
    node *newnode = new node;
    newnode->data = a;
    newnode->next = head;
    head = newnode;
}

void insert_po(int a, int pos) {
    node* newnode = new node;
    newnode->data = a;

    if (pos == 0) {
        newnode->next = head;
        head = newnode;
        return;
    }

    node* temp = head;
    int i = 0;

    while (i < pos - 1 && temp != nullptr) {
        temp = temp->next;
        i++;
    }

    if (temp == nullptr) {
        cout << endl;
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void del_st(){
    node* temp = head;
    if(temp==nullptr){
        return;
    }

    head = temp->next;
    delete temp;
}

void del_end(){

    if(head==nullptr){
        return;
    }

    if(head->next==nullptr){
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
    if(pos==1){
        del_st();
    }

    else{
        int i = 0;
        while(i< pos-1 && temp!=nullptr){
            current = temp;
            temp = temp->next;
            i++;
        }

        current->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

void search(int a){
    node* temp = head;
    int c = 1;
    while(temp->next!= nullptr){
        if(temp->data == a){
            cout<<"data found at position "<< c<< endl;
        }
        c++;
        temp = temp->next;
    }

}

void size(){
    node* temp = head;
    int a = 0;
    while(temp->next!=nullptr){
        temp = temp->next;
        a++;
    }
    cout<<"The size of the linked list is : "<<a<<endl;
}

bool isempty(){
    if(head->next==nullptr){
        return true;
    }
    else{
        return false;
    }
}

void reverse(){
    node* current = head;
    node* previous = nullptr;
    node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous; 

}

void display(){
    node* temp = head;
    while (temp!=NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    insert_start(0);
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);
    insert(80);
    insert(90);
    insert_po(96, 2);

    del_st();
    del_end();
    del_pos(9);
    display();

    search(60);

    size();

    reverse();
    display();

}
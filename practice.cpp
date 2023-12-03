#include<iostream>
using namespace std;

struct bnode{
    bnode* left;
    int data;
    bnode* right;
};
bnode* root = nullptr;

bnode* insert(bnode *root, int a){
    if(root == NULL){
        bnode* temp = new bnode;    
        temp->right = nullptr;
        temp->data = a;
        temp->left = nullptr;
        return temp;
    }

    if(root->data<a){
        root->left = insert(root->left, a);
    }
    else if(root->data>a){
        root->right = insert(root->right, a);
    }

    return root;
}

void display(bnode* root){
    if (root == nullptr) {
        return;
    }
    display(root->left);
    cout<< root->data<<" ";
    display(root->right);
}

int main(){

    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    bnode* root;

    for(int i:arr){
        root = insert(root,i);
    }
    display(root);
}
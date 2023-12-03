#include<iostream>
using namespace std;

const int size = 26;

struct Trienode{
    Trienode * children[size];
    bool eow;
};

Trienode* createnode(){
    Trienode *newnode = new Trienode;
    newnode->eow = false;
    for(int i = 0;i<size; i++){
        newnode->children[i] = nullptr;
    }
    return newnode;
}

void insert(Trienode *root, const string &word){
    Trienode* current = root;
    for(char ch : word){
        int index = ch - 'a';
        if(!current->children[index]){
            current->children[index] = createnode();
        }
        current = current->children[index];
    }
    current->eow = true;
}

bool search(Trienode * root, const string & word){
    Trienode* current = root;
    for(char ch: word){
        int index = ch - 'a';
        if(!current->children[index]){
            return false;
        }
        current = current->children[index];
    }
    return current->eow;
}

int main(){
    Trienode* root = createnode();

    insert(root, "apple");
    insert(root, "app");
    insert(root, "apricot");

    cout << "Search 'apple': " << (search(root, "apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (search(root, "app") ? "Found" : "Not Found") << endl;
    cout << "Search 'apricot': " << (search(root, "apricot") ? "Found" : "Not Found") << endl;
    cout << "Search 'banana': " << (search(root, "banana") ? "Found" : "Not Found") << endl;

    return 0;
}
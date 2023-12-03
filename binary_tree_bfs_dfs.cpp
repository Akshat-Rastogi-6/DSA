#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* root = nullptr;

node* insert(node* root, int a) {
    if (root == nullptr) {
        node* newnode = new node;
        newnode->data = a;
        newnode->right = nullptr;
        newnode->left = nullptr;
        return newnode;
    }

    if (a < root->data) {
        root->left = insert(root->left, a);
    } else if (a > root->data) {
        root->right = insert(root->right, a);
    }

    return root;
}

void dfs(node* root) {
    if (root) {
        cout << root->data << " ";
        dfs(root->left);
        dfs(root->right);
    }
}

void bfs(node* root) {
    if (root == nullptr) {
        return;
    }

    node* q[100];
    int front = 0, rear = 0;

    q[rear++] = root;

    while (front < rear) {
        node* current = q[front++];
        cout << current->data << " ";

        if (current->left) {
            q[rear++] = current->left;
        }
        if (current->right) {
            q[rear++] = current->right;
        }
    }
}

int main() {
    root = insert(root, 25);
    insert(root, 29);
    insert(root, 23);
    insert(root, 28);
    insert(root, 30);
    insert(root, 24);
    insert(root, 27);
    insert(root, 22);
    insert(root, 26);
    insert(root, 21);

    cout << "DFS traversal: ";
    dfs(root);
    cout << endl;

    cout << "BFS traversal: ";
    bfs(root);
    cout << endl;

    return 0;
}

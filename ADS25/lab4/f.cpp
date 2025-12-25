#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int val) {
        data = val;
        right = nullptr;
        left = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if(root == nullptr) {
        return new Node(val);
    }

    if(val > root->data) {
        root->right = insert(root->right, val);
    } else {
        root->left = insert(root->left, val);
    }

    return root;
}

int Triangle(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    int count = 0;
    if(root->left && root->right) {
        count++;
    } 

    count+= Triangle(root->left);
    count += Triangle(root->right);

    return count;

    
}

int main() {
    int n;
    cin >> n ;
    Node* root = nullptr;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        root = insert(root, x);
    }

    cout << Triangle(root);
}
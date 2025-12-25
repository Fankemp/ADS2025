#include<iostream>

using namespace std;

struct Node {
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
    } else if(val < root->data) {
        root->left = insert(root->left, val);
    } else if(val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* subtree(Node* root, int val) {
    if(root->data == val) {
        return root;
    }
    if(root->data > val) {
        return subtree(root->left, val);
    } else {
        return subtree(root->right, val);
    }
}

void pre_order(Node* root) {
    if(root == nullptr) {
        return;
    }

    cout << root->data << " ";

    pre_order(root->left);
    pre_order(root->right);
} 

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int num;
    cin >> num;

    Node* temp = subtree(root, num);
    pre_order(temp);
}
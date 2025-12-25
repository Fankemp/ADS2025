#include<iostream>
#include<algorithm>

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

    if(val < root->data) {
        root->left = insert(root->left, val);
    } else if(val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

int diameter(Node* root, int& maxdi) {
    if(root == nullptr) {
        return 0;
    }

    int leftDep = diameter(root->left, maxdi);
    int rightDep = diameter(root->right, maxdi);

    maxdi = max(maxdi, leftDep + rightDep);

    return max(leftDep, rightDep) + 1;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for(int i = 0; i < n; i++) {
        int x;
        cin >>x;
        root = insert(root, x);
    }

    int maxdi = 0;
    diameter(root, maxdi);
    cout << maxdi + 1;
}
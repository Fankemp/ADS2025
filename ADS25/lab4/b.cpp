#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
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
    if(root == nullptr) {
        return nullptr;
    }
    
    if(root->data == val) {
        return root;
    }
    
    if(val < root->data) {
        return subtree(root->left, val);
    } else {
        return subtree(root->right, val);
    }
}

int CountTree(Node* root) {
    if(root == nullptr) {
        return 0;
    }

    int leftSize = CountTree(root->left);
    int rightSize = CountTree(root->right);

    return 1 + leftSize + rightSize;
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


    Node* targetNode = subtree(root, num);

    if(targetNode != nullptr) {
        cout << CountTree(targetNode);
    } else {
        cout << 0;
    }
}
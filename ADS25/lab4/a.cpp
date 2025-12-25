#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
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


bool Mount(Node* root, string s) {
    Node* cur = root;

    for(char c : s) {
        if(cur == nullptr) {
            return false;
        }
        if(c == 'L') {
            cur = cur->left;
        } else if(c == 'R') {
            cur = cur->right;
        }  
    }
    return cur != nullptr;
}

int main() {
    int n, q;
    cin >> n >> q;
    Node* root = nullptr;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    for(int i = 0; i < q; i++) {
        string s;
        cin >> s;

        if(Mount(root, s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

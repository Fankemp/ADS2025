#include <iostream>
using namespace std;

struct Node {
    int val;
    int count;
    Node *left, *right;
    
    Node(int x) : val(x), count(1), left(nullptr), right(nullptr) {}
};

Node* getMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* insert(Node* node, int val) {
    if (node == nullptr) return new Node(val);

    if (val < node->val) {
        node->left = insert(node->left, val);
    } else if (val > node->val) {
        node->right = insert(node->right, val);
    } else {
        node->count++;
    }
    return node;
}

Node* deleteNode(Node* node, int val) {
    if (node == nullptr) return nullptr;

    if (val < node->val) {
        node->left = deleteNode(node->left, val);
    } else if (val > node->val) {
        node->right = deleteNode(node->right, val);
    } else {
        if (node->count > 1) {
            node->count--;
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = getMin(node->right);
            node->val = temp->val;
            node->count = temp->count;
            node->right = deleteNode(node->right, temp->val);
        }
    }
    return node;
}

int findCount(Node* node, int val) {
    if (node == nullptr) return 0;

    if (val < node->val) {
        return findCount(node->left, val);
    } else if (val > node->val) {
        return findCount(node->right, val);
    } else {
        return node->count;
    }
}

int main() {
    int q;
    cin >> q;

    Node* root = nullptr;
    string operation;
    int value;

    for (int i = 0; i < q; i++) {
        cin >> operation >> value;

        if (operation == "insert") {
            root = insert(root, value);
        } else if (operation == "delete") {
            root = deleteNode(root, value);
        } else if (operation == "cnt") {
            cout << findCount(root, value) << endl;
        }
    }

    return 0;
}

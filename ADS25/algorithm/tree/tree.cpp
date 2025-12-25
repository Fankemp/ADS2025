#include<iostream>
#include<queue>

using namespace std;

struct Node { // структура для деревья
    int data;
    Node* right;
    Node* left;

    Node(int val) {
        data = val;
        right = nullptr;
        left = nullptr;
    }
};


 Node* insert(Node* root, int val) { // добавляем элементы
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


Node* insert(Node* root, int val) {
    if(root == nullptr) {
        return;
    }

    
}



void preOrder(Node* root) {
    if(root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root) {
    if(root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(Node* root) {
    if(root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void levelOrder(Node* root) { // в ширину выводим 
    if(root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* current = q.front(); q.pop();
        cout << current->data << " ";

        if(current -> left) {
            q.push(current->left);
        }

        if(current ->right) {
            q.push(current->right);
        }
    }
}

Node* findMin(Node* root) {
    while(root && root->left) {
        root = root->left;
    }
    return root;
}

Node* findMax(Node* root) {
    while(root && root->right) {
        root = root->right;
    }

    return root;
}


int main() {

}
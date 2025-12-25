#include<iostream>
#include<queue>

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

void insert(Node*& root, int x, int y, int z) {
    if(root == nullptr) {                                                                                                  
        root = new Node(x);
    }

    queue<Node*> q;
    q.push(root);
    Node* parentNode = nullptr;

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp->data == x) {
            parentNode = temp;
            break;
        }

        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }

    if(parentNode) {
        if(z == 1) {
            parentNode->right = new Node(y);
        } else {
            parentNode->left = new Node(y);
        }
    }
}

int maxFind(Node* root) {
    if(root == nullptr) {
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int maxWidth = 0;

    while(!q.empty()) {
        int levelSize = q.size();
        maxWidth = max(maxWidth, levelSize);

        for(int i = 0; i < levelSize; i++) {
            Node* temp = q.front();
            q.pop();

            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }

    return maxWidth;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for(int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        insert(root, x, y, z);
    }

    cout << maxFind(root);
}

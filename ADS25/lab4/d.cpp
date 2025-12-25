#include <iostream>
#include <vector>
#include <queue>
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
    }

    if(val < root->data) {
        root->left = insert(root->left, val);
    } else if(val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

void findLVl(Node* root, int& maxlvl, vector<int>& vec) {
    if(root == nullptr) {
        return;
    }

    queue<pair<Node*,int >> q;
    q.push({root, 0});

    while(!q.empty()) {
        Node* currentNode = q.front().first;
        int currentLvl =  q.front().second;
        q.pop();

        if(currentLvl >= vec.size()) {
            vec.push_back(0);
        }

        vec[currentLvl] += currentNode->data;
        maxlvl = max(maxlvl, currentLvl);

        if(currentNode->left != nullptr) {
            q.push({currentNode->left, currentLvl + 1});
        } 

        if(currentNode->right != nullptr) {
            q.push({currentNode->right, currentLvl + 1});
        }
    }
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

    vector<int> vec;
    int maxlvl = -1;

    findLVl(root, maxlvl, vec);

    cout << maxlvl  + 1 << " ";

    for(int i = 0; i < vec.size();i++) {
        cout << vec[i] << " ";
    }
}
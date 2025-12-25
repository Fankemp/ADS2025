#include<iostream>
#include<algorithm>
#include <cmath>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;


    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        Node* newNode = new Node{num, nullptr};

        if(!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int target;
    cin >> target;

    Node* current = head;

    int ind = 0;
    int minInd = 0;
    int minDist = abs(head->data - target);

    while(current != nullptr) {
        int dist = abs(current->data - target);
        if(dist < minDist) {
            minDist = dist;
            minInd = ind;
        }
        ind++;
        current = current -> next;
    }

    cout << minInd << endl;
}
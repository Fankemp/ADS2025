#include<iostream>

using namespace std;
// 1->2->3->4  
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
        Node* nodeNum = new Node{num, nullptr};
        if(!head) {
            head = nodeNum;
            tail = nodeNum;
        } else {
            tail->next = nodeNum;
            tail = nodeNum;
        }
    }

    int elem, p;
    cin >> elem >> p;

    
    Node* newNode = new Node{elem, nullptr};

    if(p == 0) {
        newNode ->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        int count = 0;

        while(temp && count < p - 1) {
            temp = temp->next;
            count++;
        }

        if(temp) {
            newNode->next = temp->next;
            temp->next = newNode;   
        }
    }

    Node* tempi = head;
    while(tempi) {
        cout << tempi->data << " ";
        tempi = tempi->next;
    }

}
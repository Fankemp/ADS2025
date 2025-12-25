#include<iostream>

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

        Node* newArray = new Node{num, nullptr};

        if(!head) {
            head = newArray;
            tail = newArray;
        } else {
            tail->next = newArray;
            tail = newArray;
        }
    }

    Node* current = head;
    Node* prev = nullptr;
    int ind = 0;

    while(current != nullptr) {
        if(ind % 2 == 1) {
            Node* toDelete = current;
            if(prev != nullptr) {
                 prev->next = current->next;
            }
            current = current->next;
            delete toDelete;
        } else {
            prev = current;
            cout << current->data << " ";
            current = current->next;
        }

        ind++;
    }




}
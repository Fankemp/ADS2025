#include<iostream>
#include<string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

int main() { 
    int n, len;
    cin >> n >> len;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        Node* newString = new Node{s, nullptr};

        if(!head) {
            head = newString;
            tail  = newString;
        } else {
            tail->next = newString;
            tail = newString;
        }
    }

    Node* current = head;

    for(int i = 1; i < len; i++) {
        current = current->next;    
    }

    Node* newHead = current->next;
    current -> next = nullptr;

    tail->next = head;

    current = newHead;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }


}
  
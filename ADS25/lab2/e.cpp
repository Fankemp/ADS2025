#include<iostream>

using namespace std;

struct Node {
    string  data;
    Node* next;
};

void insert(Node*& head, string s) {
    Node* newNode = new Node{s, head};
    head = newNode;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;
    string prev;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout;
        
        if(s != prev) {
            insert(head, s);
        }
        prev = s;
    }

    int count = 0;
    Node* chech = head;

    while(chech) {
        count++;
        chech = chech ->next;
    }

    cout << "All in all: " << count << " " << endl;
    cout << "Students:" << endl;

    Node* temp = head;
    while(temp) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
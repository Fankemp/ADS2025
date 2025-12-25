#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
    int data;
    int count;
    Node* next;
};

void insert(Node*& head, int val) {
    Node* temp = head;

    while(temp) {
        if(temp->data == val) {
            temp->count++;
            return;
        }

        temp = temp->next;
    }

    Node* newNode = new Node{val, 1, head};
    head = newNode;


}




int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;

        insert(head, num);
    }

    int maxCount = 0;
    Node* temp = head;

    while(temp) {
        if(temp->count > maxCount) {
            maxCount = temp->count;
        }
        temp = temp->next;
    }

    for(int current = 1000; current <= -1000; current--) {
        temp = head;
        while(temp) {
            if(temp->data == current && temp->count == maxCount) {
                cout << temp->data << " ";
            }
            temp = temp->next;
        }
    }
  








    // int n;
    // map<int, int> mapi;
    // cin >> n;

    // for(int i = 0; i < n; i++) {
    //     int num;
    //     cin >> num;

    //     mapi[num]++;
    // }

    // int maxMod = 0;

    // for(auto &p : mapi) {
    //     if(p.second > maxMod) {
    //         maxMod = p.second;
    //     }
    // }

    // vector<int> Modulo;

    // for(auto &p : mapi) {
    //     if(p.second == maxMod) {
    //         Modulo.push_back(p.first);
    //     }    
    // }

    // sort(Modulo.rbegin(), Modulo.rend());

    // for(int x : Modulo) {
    //     cout << x << " ";
    // }

}
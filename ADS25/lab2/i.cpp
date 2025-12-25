#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    
    Node(const string& value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void add_front(const string& value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "ok" << endl;
    }
    
    void add_back(const string& value) {
        Node* newNode = new Node(value);
        
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "ok" << endl;
    }
    
    void erase_front() {
        if (head == nullptr) {
            cout << "error" << endl;
            return;
        }
        
        Node* temp = head;
        string erasedValue = temp->data;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        
        delete temp;
        cout << erasedValue << endl;
    }
    
    void erase_back() {
        if (tail == nullptr) {
            cout << "error" << endl;
            return;
        }
        
        Node* temp = tail;
        string erasedValue = temp->data;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        
        delete temp;
        cout << erasedValue << endl;
    }
    
    void front() const {
        if (head == nullptr) {
            cout << "error" << endl;
        } else {
            cout << head->data << endl;
        }
    }
    
    void back() const {
        if (tail == nullptr) {
            cout << "error" << endl;
        } else {
            cout << tail->data << endl;
        }
    }
    
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "ok" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    string command;
    
    while (true) {
        cin >> command;
        if (command == "add_front") {
            string book;
            cin >> book;
            list.add_front(book);
        } else if (command == "add_back") {
            string book;
            cin >> book;
            list.add_back(book);
        } else if (command == "erase_front") {
            list.erase_front();
        } else if (command == "erase_back") {
            list.erase_back();
        } else if (command == "front") {
            list.front();
        } else if (command == "back") {
            list.back();
        } else if (command == "clear") {
            list.clear();
        } else if (command == "exit") {
            cout << "goodbye" << endl;
            return 0; 
        }
    }
}
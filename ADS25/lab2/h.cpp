#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){
    if(p == 0) {
        node ->next = head;
        head = node;
        return head;
    } else {
        int count = 0;
        Node* temp = head;

        while(temp && count < p - 1) {
            temp = temp->next;
            count++;
        }

        if(temp) {
            node->next = temp->next;
            temp->next = node;
        }
    }

    return head;
}
 
Node* remove(Node* head, int p){
    if (!head) return nullptr;

    if(p == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        int count = 0;
        Node* tempi = head;

        while(tempi && count < p - 1) {
            tempi = tempi->next;
            count++;
        }


        if(tempi) {
            Node* nodDel = tempi->next;
            tempi->next = tempi->next->next;
            delete nodDel;

        }       
    }

    return head;

}
 
Node* replace(Node* head, int p1, int p2){
    if (p1 == p2) return head;

    Node* temp = head;
    Node* prev_p1 = nullptr;
    Node* node_p1 = nullptr;

    for (int i = 0; temp && i < p1; i++) {
        prev_p1 = temp;
        temp = temp->next;
    }


    node_p1 = temp;  
    if (prev_p1) {
        prev_p1->next = temp->next;  
    } else {
        head = temp->next;  
    }

    
    if (p2 == 0) {
        node_p1->next = head;
        head = node_p1;  
        return head;
    }

    
    temp = head;
    Node* prev_p2 = nullptr;
    for (int i = 0; temp && i < p2; i++) {
        prev_p2 = temp;
        temp = temp->next;
    }

    if (prev_p2) {
        prev_p2->next = node_p1;
        node_p1->next = temp;  
    } else {
        node_p1->next = head;
        head = node_p1;  
    }

    return head;
}
 
Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* current  = head;
    Node* next  = nullptr;

    // 1->2->3->4->5
    while(current) {
        next = current->next; // ->2
        current->next = prev; // указатель на предыдущий элемент
        prev = current; // 1 станет предыдущим
        current = next; //  двигаемся дальше принимаем 2     
    }
    head = prev;
    return head;
}
 
void print(Node* head){
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
}
 
Node* cyclic_left(Node* head, int x){
    if (!head || !head->next) return head;

    Node* temp = head;
    int length = 1;

    while(temp->next) {
        temp = temp->next;
        length++;
    }

    x = x % length;  
    if (x == 0) return head;  


    Node* current = head;
    for(int i = 1; i < x; i++) {
        current = current->next;
    }

    Node* new_head = current->next;
    current->next = nullptr; // 1->2->3->4->5
    temp->next = head;

    return new_head;
}
 
Node* cyclic_right(Node* head, int x){
    if (!head || !head->next) return head;
    Node* temp = head;
    int length = 1;
    while (temp->next) {
        temp = temp->next;
        length++;
    }

    return cyclic_left(head, length - x );
}
 
int main(){
    Node* head = nullptr;
    
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
            cout << endl;
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
            cout << endl;
        }else if (command == 3){
            print(head);
            cout << endl;
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
            cout << endl;
        }else if (command == 5){
            head = reverse(head);
            cout << endl;
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
            cout << endl;
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
            cout << endl;
        }   
    }
    return 0;
}
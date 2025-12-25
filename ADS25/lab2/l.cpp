#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node() {
        val = 0;
        next = NULL;
    }
};

int findMaxSum(int n, Node *head) {
    int max_sum = head->val;
    int current_sum = head->val;
    Node* current = head->next;

    while (current != NULL) {
        current_sum = max(current_sum + current->val, current->val);
        max_sum = max(max_sum, current_sum);
        current = current->next;
    }
    
    return max_sum;
}

int main() {
    int n;
    cin >> n;

    Node *head = NULL, *tail = NULL;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        Node *cur = new Node();
        cur->val = x;

        if (i == 1) {
            head = tail = cur;
        } else {
            tail->next = cur;
            tail = cur;
        }
    }

    cout << findMaxSum(n, head) << "\n";
    return 0;
}

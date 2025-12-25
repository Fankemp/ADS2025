#include<iostream>
#include<queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        pq.push(x);
    }
    
    while(pq.size() > 1) {
        int max1 = pq.top(); pq.pop();
        int max2 = pq.top(); pq.pop();

       if (max1 != max2) {
            int diff = abs(max1 - max2);
            pq.push(diff);
        }
    }

    if(pq.size() == 0) {
        cout << 0;
    } else {
        cout << pq.top();
    }
    
}
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    int op = 0;
    bool possible = true;
    
    while(pq.size() > 1 && pq.top() < m) {
        long long min1 = pq.top(); pq.pop();
        long long min2 = pq.top(); pq.pop();

        if (min1 + 2 * min2 <= min1 && min1 + 2 * min2 <= min2) {
            possible = false;
            break;
        }

        long long sum = min1 + 2 * min2;
        op++;
        pq.push(sum);
    }

    if (pq.top() < m) {
        possible = false;
    }

    if (possible) {
        cout << op << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}

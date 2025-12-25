#include<iostream>
#include<queue>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    priority_queue<long long> pq;

    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    long long total = 0;

    for(int i = 0; i < m; i++) {
        long long max = pq.top();
        pq.pop();
        total+= max;
        long long jj = max - 1;
        pq.push(jj);
    }

    cout << total;



}
#include<iostream>
#include<queue>
using namespace std;



int main() {
    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(x);
    }

    long long total = 0;

    while(pq.size() > 1) {
       long long n1 = pq.top();
        pq.pop();
        long long n2  = pq.top();
        pq.pop();

        total += n1 + n2;
        long long minel = n1 + n2;
        pq.push(minel);
    }

    cout << total;

}
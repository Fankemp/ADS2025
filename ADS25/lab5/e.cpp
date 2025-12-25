#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long total_sum = 0;  

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "print") {
            cout << total_sum << endl;
        } 
        else if (s == "insert") {
            long long x;
            cin >> x;

            
            if (pq.size() < m) {
                pq.push(x);  
                total_sum += x;  
            } 
            else {
                if (x > pq.top()) {
                    total_sum += x - pq.top(); 
                    pq.pop();
                    pq.push(x);
                }
            }
        }
    }

    return 0;
}

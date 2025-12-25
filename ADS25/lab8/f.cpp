#include <bits/stdc++.h>
using namespace std;

const long long M1 = 1000000007;
const long long M2 = 1000000009;
const long long P1 = 31;
const long long P2 = 37;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<long long> h1(n+1), h2(n+1), p1(n+1), p2(n+1);
    p1[0] = 1;
    p2[0] = 1;


    for (int i = 1; i <= n; i++) {
        p1[i] = (p1[i-1] * P1) % M1;
        p2[i] = (p2[i-1] * P2) % M2;
    }


    for (int i = 0; i < n; i++) {
        long long x = (s[i] - 'a' + 1);
        h1[i+1] = (h1[i] * P1 + x) % M1;
        h2[i+1] = (h2[i] * P2 + x) % M2;
    }

    set<pair<long long,long long>> st;


    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r <= n; r++) {
            long long a = (h1[r] - (h1[l] * p1[r-l]) % M1 + M1) % M1;
            long long b = (h2[r] - (h2[l] * p2[r-l]) % M2 + M2) % M2;

            st.insert( make_pair(a, b) ); 
        }
    }

    cout << st.size() << "\n";
    return 0;
}
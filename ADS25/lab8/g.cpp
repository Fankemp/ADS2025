#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M1 = 1000000007, M2 = 1000000009;
const ll P = 31;

string s;
vector<ll> h1, h2, p1, p2;

pair<ll,ll> get_hash(int l, int r){
    ll x1 = (h1[r+1] - h1[l] * p1[r-l+1] % M1 + M1) % M1;
    ll x2 = (h2[r+1] - h2[l] * p2[r-l+1] % M2 + M2) % M2;
    return {x1, x2};
}

int main(){
    cin >> s;
    int n = s.size();

    h1.assign(n+1,0);
    h2.assign(n+1,0);
    p1.assign(n+1,1);
    p2.assign(n+1,1);

    for(int i=0;i<n;i++){
        h1[i+1] = (h1[i] * P + (s[i]-'a'+1)) % M1;
        h2[i+1] = (h2[i] * P + (s[i]-'a'+1)) % M2;
        p1[i+1] = (p1[i] * P) % M1;
        p2[i+1] = (p2[i] * P) % M2;
    }

    unordered_map<long long, int> cnt;
    cnt.reserve(n * n);

    for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            auto H = get_hash(l,r);
            long long key = (H.first << 32) ^ H.second; 
            cnt[key]++;
        }
    }

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;

        auto H = get_hash(l,r);
        long long key = (H.first << 32) ^ H.second;

        cout << cnt[key] << "\n";
    }
    return 0;
}
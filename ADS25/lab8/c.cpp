#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll P = 31;

void build_hash(const string &s, vector<ll> &h, vector<ll> &p) {
    int n = s.size();
    h.assign(n + 1, 0);
    p.assign(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * P + (s[i] - 'a' + 1)) % MOD;
        p[i + 1] = (p[i] * P) % MOD;
    }
}

ll get_hash(const vector<ll> &h, const vector<ll> &p, int l, int r) {
    ll res = (h[r] - h[l] * p[r - l] % MOD + MOD) % MOD;
    return res;
}

int main() {
    string big;
    cin >> big;
    int n = big.size();

    int k;
    cin >> k;

    vector<string> small(k);
    for (int i = 0; i < k; i++) cin >> small[i];

    vector<ll> hb, pb;
    build_hash(big, hb, pb);


    vector<int> cover(n, 0);

    for (int t = 0; t < k; t++) {
        string &s = small[t];
        int m = s.size();
        if (m > n) continue;

        vector<ll> hs, ps;
        build_hash(s, hs, ps);
        ll hS = get_hash(hs, ps, 0, m);

        for (int i = 0; i + m <= n; i++) {
            if (get_hash(hb, pb, i, i + m) == hS) {
                for (int j = i; j < i + m; j++) {
                    cover[j] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (cover[i] == 0) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}

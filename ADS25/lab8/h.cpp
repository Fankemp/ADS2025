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
    return (h[r] - h[l] * p[r - l] % MOD + MOD) % MOD;
}

bool contains(const string &s, const vector<ll> &h, const vector<ll> &p, const string &sub) {
    int n = s.size(), m = sub.size();
    if (m > n) return false;

    vector<ll> hs, ps;
    build_hash(sub, hs, ps);
    ll hsval = get_hash(hs, ps, 0, m);

    for (int i = 0; i + m <= n; i++) {
        if (get_hash(h, p, i, i + m) == hsval)
            return true;
    }
    return false;
}

int main() {
    int K;
    cin >> K;

    vector<string> S(K);
    for (int i = 0; i < K; i++) {
        cin >> S[i];
    }

    int id = 0;
    for (int i = 1; i < K; i++) {
        if (S[i].size() < S[id].size()) id = i;
    }
    string t = S[id];


    vector<vector<ll>> H(K), Ppow(K);
    for (int i = 0; i < K; i++) {
        build_hash(S[i], H[i], Ppow[i]);
    }

    int n = t.size();

    for (int len = n; len >= 1; len--) {
        for (int start = 0; start + len <= n; start++) {

            string sub = t.substr(start, len);

            bool ok = true;
            for (int i = 0; i < K; i++) {
                if (i == id) continue;
                if (!contains(S[i], H[i], Ppow[i], sub)) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cout << sub << "\n";
                return 0;
            }
        }
    }

    return 0;
}
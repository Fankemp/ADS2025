#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const long long P = 31;

void build_hash(string &s, vector<long long> &h, vector<long long> &p) {
    int n = s.size();
    h.assign(n + 1, 0);
    p.assign(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * P + (s[i] - 'a' + 1)) % MOD;
        p[i + 1] = (p[i] * P) % MOD;
    }
}

long long get_hash(vector<long long> &h, vector<long long> &p, int l, int r) {
    return (h[r] - h[l] * p[r - l] % MOD + MOD) % MOD;
}

int main() {
    string a, b, t;
    cin >> a >> b >> t;

    int n1 = a.size(), n2 = b.size(), m = t.size();

    vector<long long> ha, pa, hb, pb, ht, pt;
    build_hash(a, ha, pa);
    build_hash(b, hb, pb);
    build_hash(t, ht, pt);

    long long hT = get_hash(ht, pt, 0, m);

    int limit = min(n1, n2) - m + 1;
    int ans = 0;

    for (int i = 0; i < limit; i++) {
        if (get_hash(ha, pa, i, i + m) == hT &&
            get_hash(hb, pb, i, i + m) == hT)
        {
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}

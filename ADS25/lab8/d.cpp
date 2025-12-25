#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll P = 31;

vector<ll> h, pw;

ll get_hash(int l, int r) {
    return (h[r+1] - h[l] * pw[r - l + 1] % MOD + MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) return 0;

        vector<string> pat(n);
        for (int i = 0; i < n; i++) {
            cin >> pat[i];
        }

        string text;
        cin >> text;
        int T = text.size();

        h.assign(T + 1, 0);
        pw.assign(T + 1, 1);

        for (int i = 0; i < T; i++) {
            h[i + 1] = (h[i] * P + (text[i] - 'a' + 1)) % MOD;
            pw[i + 1] = (pw[i] * P) % MOD;
        }

        map<int, vector<int>> by_len;
        for (int i = 0; i < n; i++) {
            int L = pat[i].size();
            by_len[L].push_back(i);
        }

        vector<int> cnt(n, 0);

        map<ll, vector<int>> mp;
        map<int, vector<int>>::iterator it_len;
        for (it_len = by_len.begin(); it_len != by_len.end(); it_len++) {
            int L = it_len->first;
            vector<int> &indices = it_len->second;

            mp.clear();

            for (int j = 0; j < (int)indices.size(); j++) {
                int id = indices[j];
                ll hv = 0;
                for (int k = 0; k < (int)pat[id].size(); k++) {
                    hv = (hv * P + (pat[id][k] - 'a' + 1)) % MOD;
                }
                mp[hv].push_back(id);
            }

            if (L <= T) {
                for (int start = 0; start + L - 1 < T; start++) {
                    ll hv = get_hash(start, start + L - 1);
                    if (mp.find(hv) != mp.end()) {
                        vector<int> &v = mp[hv];
                        for (int x = 0; x < (int)v.size(); x++) {
                            cnt[v[x]]++;
                        }
                    }
                }
            }
        }

        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > mx) mx = cnt[i];
        }

        cout << mx << "\n";

        for (int i = 0; i < n; i++) {
            if (cnt[i] == mx) {
                cout << pat[i] << "\n";
            }
        }
    }
}

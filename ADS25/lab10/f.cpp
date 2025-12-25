#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int s, f;
    cin >> s >> f;

    vector<bool> used(n + 1, false);
    queue<int> q;
    q.push(s);
    used[s] = true;

    bool ok = false;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == f) {
            ok = true;
            break;
        }

        for (int to : g[v]) {
            if (!used[to]) {
                used[to] = true;
                q.push(to);
            }
        }
    }

    cout << (ok ? "YES\n" : "NO\n");

    return 0;
}

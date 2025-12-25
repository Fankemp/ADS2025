#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> color, parent;
int n, m;

int s = -1, t = -1;

bool dfs(int v) {
    color[v] = 1;
    for (int to : g[v]) {
        if (color[to] == 0) {
            parent[to] = v;
            if (dfs(to)) return true;
        } else if (color[to] == 1) {
            s = to;
            t = v;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool hasCycle(int skip_u = -1, int skip_v = -1) {
    vector<int> col(n + 1, 0);

    function<bool(int)> go = [&](int v) {
        col[v] = 1;
        for (int to : g[v]) {
            if (v == skip_u && to == skip_v) continue;
            if (col[to] == 0) {
                if (go(to)) return true;
            } else if (col[to] == 1)
                return true;
        }
        col[v] = 2;
        return false;
    };

    for (int i = 1; i <= n; i++)
        if (col[i] == 0)
            if (go(i)) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    // Find any cycle
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0)
            if (dfs(i)) break;
    }

    // No cycles at all -> already DAG
    if (s == -1) {
        cout << "YES\n";
        return 0;
    }

    // Reconstruct cycle
    vector<pair<int,int>> edges;
    int v = t;
    edges.emplace_back(t, s);
    while (v != s) {
        int p = parent[v];
        edges.emplace_back(p, v);
        v = p;
    }

    // Try removing each edge of this cycle
    for (auto [u, v] : edges) {
        if (!hasCycle(u, v)) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int INF = 1000000000;

// Алгоритм Дейкстры
vector<int> dijkstra(int start, const vector<vector<pair<int, int>>>& g) {
    int n = g.size();
    vector<int> dist(n, INF);
    dist[start] = 0;

    using PII = pair<int, int>;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : g[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    int s, t, p, gma;
    cin >> s >> t >> p >> gma;
    s--; t--; p--; gma--;

    vector<int> ds = dijkstra(s, g);
    vector<int> dt = dijkstra(t, g);
    vector<int> dp = dijkstra(p, g);

    int way1 = INF, way2 = INF;

    // s -> t -> p -> gma
    if (ds[t] != INF && dt[p] != INF && dp[gma] != INF) {
        way1 = ds[t] + dt[p] + dp[gma];
    }

    // s -> p -> t -> gma
    if (ds[p] != INF && dp[t] != INF && dt[gma] != INF) {
        way2 = ds[p] + dp[t] + dt[gma];
    }

    int ans = min(way1, way2);

    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
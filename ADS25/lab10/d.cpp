#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> dist(n + 1, INF);
    vector<bool> is_red(n + 1, false);
    queue<int> bfs_queue;
    bool need_bfs = false;
    
    while (q--) {
        int type, x;
        cin >> type >> x;
        
        if (type == 1) {
            if (!is_red[x]) {
                is_red[x] = true;
                dist[x] = 0;
                bfs_queue.push(x);
                need_bfs = true;
            }
        } else {
            if (need_bfs) {
                while (!bfs_queue.empty()) {
                    int u = bfs_queue.front();
                    bfs_queue.pop();
                    
                    for (int v : graph[u]) {
                        if (dist[v] > dist[u] + 1) {
                            dist[v] = dist[u] + 1;
                            bfs_queue.push(v);
                        }
                    }
                }
                need_bfs = false;
            }
            
            cout << (dist[x] == INF ? -1 : dist[x]) << "\n";
        }
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// BFS для поиска кратчайшего пути
int bfs(int start, int end, vector<vector<int>>& graph, vector<bool>& forbidden) {
    int n = graph.size();
    vector<int> dist(n, -1);
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u == end) return dist[end];
        
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (dist[v] == -1 && !forbidden[v]) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return -1;
}

// BFS с сохранением пути
int bfsWithPath(int start, int end, vector<vector<int>>& graph, vector<bool>& forbidden, vector<int>& path) {
    int n = graph.size();
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);
    queue<int> q;
    
    dist[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        if (u == end) {
            // Восстанавливаем путь
            int curr = end;
            while (curr != -1) {
                path.push_back(curr);
                curr = parent[curr];
            }
            reverse(path.begin(), path.end());
            return dist[end];
        }
        
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (dist[v] == -1 && !forbidden[v]) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // Строим граф железных дорог
    vector<vector<bool>> hasRailway(n, vector<bool>(n, false));
    vector<vector<int>> railway(n);
    vector<vector<int>> airline(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        hasRailway[u][v] = true;
        hasRailway[v][u] = true;
        railway[u].push_back(v);
        railway[v].push_back(u);
    }
    
    // Строим граф авиалиний (дополнение)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!hasRailway[i][j]) {
                airline[i].push_back(j);
                airline[j].push_back(i);
            }
        }
    }
    
    int start = 0;
    int end = n - 1;
    
    // Попробуем найти путь для Nugman, затем для Olzhas с запретом на внутренние вершины
    vector<bool> forbidden(n, false);
    vector<int> nugmanPath;
    
    int nugmanDist = bfsWithPath(start, end, railway, forbidden, nugmanPath);
    
    if (nugmanDist == -1) {
        cout << -1 << "\n";
        return 0;
    }
    
    // Запрещаем внутренние вершины пути Nugman для Olzhas
    for (int i = 1; i < nugmanPath.size() - 1; i++) {
        forbidden[nugmanPath[i]] = true;
    }
    
    int olzhasDist = bfs(start, end, airline, forbidden);
    
    if (olzhasDist == -1) {
        cout << -1 << "\n";
    } else {
        cout << max(nugmanDist, olzhasDist) << "\n";
    }
    
    return 0;
}
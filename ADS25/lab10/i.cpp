#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    vector<int> in_degree(n + 1, 0);
    
    // Читаем рёбра и строим граф
    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        graph[i].push_back(j);
        in_degree[j]++;
    }
    
    // Очередь для вершин с in-degree = 0
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result;
    
    // Алгоритм Кана
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        for (int v : graph[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    // Проверяем, все ли вершины были обработаны
    if (result.size() != n) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
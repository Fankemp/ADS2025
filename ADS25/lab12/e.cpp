#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int INF = 100000;
long long LLINF = 1e18;

int main() {    
    int n;
    cin >> n;
    
    vector<vector<int>> graph(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    // Алгоритм Беллмана-Форда
    vector<long long> dist(n, 0);  // Начинаем с 0 для всех вершин
    vector<int> parent(n, -1);
    int cycleVertex = -1;
    
    // n итераций (n-1 для кратчайших путей + 1 для поиска цикла)
    for (int iter = 0; iter < n; iter++) {
        cycleVertex = -1;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graph[u][v] != INF) {
                    if (dist[u] + graph[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph[u][v];
                        parent[v] = u;
                        if (iter == n - 1) {
                            cycleVertex = v;
                        }
                    }
                }
            }
        }
    }
    
    if (cycleVertex == -1) {
        cout << "NO\n";
        return 0;
    }
    
    // Восстанавливаем цикл
    // Поднимаемся на n шагов назад, чтобы гарантированно попасть в цикл
    for (int i = 0; i < n; i++) {
        cycleVertex = parent[cycleVertex];
    }
    
    // Восстанавливаем сам цикл
    vector<int> cycle;
    int current = cycleVertex;
    
    while (true) {
        cycle.push_back(current);
        current = parent[current];
        if (current == cycleVertex && cycle.size() > 1) {
            cycle.push_back(current);
            break;
        }
    }
    
    reverse(cycle.begin(), cycle.end());
    
    cout << "YES\n";
    cout << cycle.size() << "\n";
    for (int i = 0; i < cycle.size(); i++) {
        cout << cycle[i] + 1;  // Переводим в 1-индексацию
        if (i < cycle.size() - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}
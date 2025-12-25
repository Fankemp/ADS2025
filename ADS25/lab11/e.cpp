#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100005];

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        parent[px] = py;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int> > edges;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
    }
    
    // Инициализация
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    vector<int> result;
    vector<bool> active(n + 1, false);
    int components = 0;
    
    // Идем в обратном порядке - добавляем вершины от n до 1
    for (int step = n; step >= 1; step--) {
        // Сначала сохраняем текущее состояние (ДО добавления вершины step)
        result.push_back(components);
        
        // Теперь добавляем вершину step
        active[step] = true;
        components++; // добавили новую изолированную вершину
        
        // Проверяем все ребра
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;
            
            // Если оба конца ребра уже добавлены
            if (active[u] && active[v]) {
                // Пытаемся объединить
                if (find(u) != find(v)) {
                    unite(u, v);
                    components--; // объединили две компоненты в одну
                }
            }
        }
    }
    
    // Переворачиваем результат (т.к. шли в обратном порядке)
    reverse(result.begin(), result.end());
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    
    return 0;
}
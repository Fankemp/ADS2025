#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    
    // Строим граф
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    vector<int> children_count(n + 1, 0);
    int big_fam_count = 0;
    
    // Обрабатываем каждую компоненту связности
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // Находим корень компоненты (минимальная вершина)
            queue<int> q;
            q.push(i);
            visited[i] = true;
            int root = i;
            
            // Обход для нахождения всех вершин компоненты
            vector<int> component;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                component.push_back(u);
                root = min(root, u);
                
                for (int v : graph[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            
            // Строим дерево с корнем root
            vector<bool> tree_visited(n + 1, false);
            queue<int> tree_q;
            tree_q.push(root);
            tree_visited[root] = true;
            parent[root] = -1;
            
            while (!tree_q.empty()) {
                int u = tree_q.front();
                tree_q.pop();
                
                for (int v : graph[u]) {
                    if (!tree_visited[v]) {
                        tree_visited[v] = true;
                        parent[v] = u;
                        children_count[u]++; // u - родитель v
                        tree_q.push(v);
                    }
                }
            }
        }
    }
    
    // Теперь считаем BigFam вершины
    for (int i = 1; i <= n; i++) {
        if (parent[i] == -1) {
            // Корень - всегда BigFam
            big_fam_count++;
        } else {
            // Сравниваем количество детей с родителем
            if (children_count[i] > children_count[parent[i]]) {
                big_fam_count++;
            }
        }
    }
    
    cout << big_fam_count << endl;
    
    return 0;
}
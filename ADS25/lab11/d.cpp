#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1000];

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

struct Edge {
    int u, v, cost;
};

bool compare(Edge a, Edge b) {
    return a.cost < b.cost;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int> > matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    // Инициализация
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    vector<Edge> edges;
    
    // Добавляем существующие ребра (со стоимостью 0)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                unite(i, j);
            } else {
                Edge e;
                e.u = i;
                e.v = j;
                e.cost = matrix[i][j];
                edges.push_back(e);
            }
        }
    }
    
    // Сортируем ребра по стоимости
    sort(edges.begin(), edges.end(), compare);
    
    // Добавляем ребра минимальной стоимости
    int totalCost = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            unite(u, v);
            totalCost += edges[i].cost;
        }
    }
    
    cout << totalCost << endl;
    
    return 0;
}
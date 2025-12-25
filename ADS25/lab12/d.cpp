#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int INF = 1e9;

struct Edge {
    int to;
    int weight;
};

// Модифицированный Дейкстра для минимаксного пути
int dijkstraMinMax(int start, int end, vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<int> minMaxDist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    minMaxDist[start] = 0;
    pq.push(make_pair(0, start));
    
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        int maxDist = top.first;
        int u = top.second;
        pq.pop();
        
        if (maxDist > minMaxDist[u]) continue;
        
        if (u == end) return minMaxDist[end];
        
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].to;
            int w = graph[u][i].weight;
            
            // Максимальное ребро на пути до v через u
            int newMaxDist = max(minMaxDist[u], w);
            
            if (newMaxDist < minMaxDist[v]) {
                minMaxDist[v] = newMaxDist;
                pq.push(make_pair(newMaxDist, v));
            }
        }
    }
    
    return minMaxDist[end];
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i].first >> cities[i].second;
    }
    
    if (n == 1) {
        cout << 0 << "\n";
        return 0;
    }
    
    // Строим полный граф с весами = манхэттенское расстояние
    vector<vector<Edge>> graph(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int dist = abs(cities[i].first - cities[j].first) + 
                          abs(cities[i].second - cities[j].second);
                Edge e;
                e.to = j;
                e.weight = dist;
                graph[i].push_back(e);
            }
        }
    }
    
    int result = dijkstraMinMax(0, n - 1, graph);
    
    cout << result << "\n";
    
    return 0;
}
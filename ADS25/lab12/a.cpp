#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

int main() {    
    int n;
    cin >> n;
    
    vector<vector<long long>> graph(n, vector<long long>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
        order[i]--;
    }
    
    vector<vector<long long>> dist(n, vector<long long>(n, INF));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }
    
    vector<bool> active(n, false);
    
    for (int step = 0; step < n; step++) {
        int k = order[step];
        active[k] = true;
        
        for (int i = 0; i < n; i++) {
            dist[k][i] = min(dist[k][i], graph[k][i]);
            dist[i][k] = min(dist[i][k], graph[i][k]);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        long long maxDist = 0;
        for (int i = 0; i < n; i++) {
            if (!active[i]) continue;
            for (int j = 0; j < n; j++) {
                if (!active[j]) continue;
                if (dist[i][j] != INF) {
                    maxDist = max(maxDist, dist[i][j]);
                }
            }
        }
        
        cout << maxDist << "\n";
    }
    
    return 0;
}
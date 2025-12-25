#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // читаем матрицу смежности
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    int start, finish;
    cin >> start >> finish;

    // переводим к 0-индексации (в коде вершины 0..n-1)
    start--;
    finish--;

    // массив расстояний: -1 = не посещали
    vector<int> dist(n, -1);

    queue<int> q;

    // запускаем BFS из вершины start
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        // смотрим все возможные соседи v
        for (int u = 0; u < n; u++) {
            // если есть ребро v - u и u ещё не посещали
            if (g[v][u] == 1 && dist[u] == -1) {
                dist[u] = dist[v] + 1; // расстояние до u = расстояние до v + 1 ребро
                q.push(u);
            }
        }
    }

    // если dist[finish] осталось -1, пути нет
    cout << dist[finish] << '\n';

    return 0;
}

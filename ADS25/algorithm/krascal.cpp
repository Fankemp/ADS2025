#include <iostream>
#include <vector>

using namespace std;

// Структура для представления рёбер графа
struct Edge {   
    int u, v, weight;
};

// Функция для сортировки рёбер слиянием
void merge(vector<Edge>& edges, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge(edges, left, mid);  // Сортировка левой половины
    merge(edges, mid + 1, right);  // Сортировка правой половины

    // Слияние отсортированных частей
    vector<Edge> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (edges[i].weight <= edges[j].weight) {
            temp[k++] = edges[i++];
        } else {
            temp[k++] = edges[j++];
        }
    }

    // Копирование оставшихся элементов
    while (i <= mid) temp[k++] = edges[i++];
    while (j <= right) temp[k++] = edges[j++];

    // Перезаписываем отсортированные элементы обратно
    for (i = left; i <= right; ++i) edges[i] = temp[i - left];
}

// Функция для поиска родителя вершины в структуре Union-Find
int findParent(int parent[], int i) {
    if (parent[i] != i) {
        parent[i] = findParent(parent, parent[i]);
    }
    return parent[i];
}

// Функция для объединения двух множеств
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // n - количество вершин, m - количество рёбер

    vector<Edge> edges(m);

    // Ввод рёбер
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Сортировка рёбер по весу слиянием
    merge(edges, 0, m - 1);

    int parent[n + 1], rank[n + 1];
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }

    vector<Edge> mst;
    int mstWeight = 0;

    // Основная часть алгоритма
    for (int i = 0; i < m; ++i) {
        int u = edges[i].u, v = edges[i].v;
        if (findParent(parent, u) != findParent(parent, v)) {
            mst.push_back(edges[i]);
            mstWeight += edges[i].weight;
            unionSets(parent, rank, u, v);
        }
    }

    cout << "Минимальный остовный граф (МСТ):\n";
    for (int i = 0; i < mst.size(); ++i) {
        cout << mst[i].u << " - " << mst[i].v << ": " << mst[i].weight << endl;
    }
    cout << "Сумма весов рёбер: " << mstWeight << endl;

    return 0;
}

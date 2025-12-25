#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


struct Edge {
    int u, v, weight;
};

void MergeSort(vector<Edge>& edges, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left +(right - left) / 2;
    MergeSort(edges, left, mid);
    MergeSort(edges, mid + 1, right);

    vector<Edge> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= right) {
        if(edges[i].weight <= edges[j].weight) {
            temp[k++] = edges[i++];
        } else {
            temp[k++] = edges[j++];
        }
    }

    while(i <= mid){
        temp[k++] = edges[i++];
    }

    while(j <= right) {
        temp[k++] = edges[j++];
    }


    for(int i = left; i <= right; i++) {
        edges[i] = temp[i - left];
    }
}

int findParent(vector<int>& parent, int i) {
    if(parent[i] == i) {
        return i;
    }
    return parent[i] = findParent(parent, parent[i]);
}

void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
    int rootX = findParent(parent, x);
    int rootY = findParent(parent, y);

    if(rootX != rootY) {
        if(rank[rootX] > rank[rootY]) {
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
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }

    vector<Edge> edges;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int cost =d[i] + d[j];
            edges.push_back({i, j, cost});
        }
    }
    MergeSort(edges, 0, edges.size() - 1);

    vector<int> parent(n);
    vector<int> rank(n, 0);

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int mst_weight = 0;
    int edges_used = 0;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if(findParent(parent, u) != findParent(parent, v)) {
            mst_weight += weight;
            unionSets(parent, rank, u, v);
            edges_used++;

            if(edges_used == n - 1) {
                break;
            }
        }
    }

    cout << mst_weight << endl;


}
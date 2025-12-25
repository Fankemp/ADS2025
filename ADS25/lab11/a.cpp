#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Edge {
    int u, v, weight;
};


void mergeSort(vector<Edge>& edges, int left, int right) {
    if(left >= right) {
        return;
    } 

    int mid = left + (right - left) / 2;
    mergeSort(edges, left, mid);
    mergeSort(edges, mid+1, right);

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

    while(i <= mid) {
        temp[k++] = edges[i++];
    }

    while(j <= right) {
        temp[k++] = edges[j++];
    }

    for(int i = left; i <= right; i++) {
        edges[i] = temp[i - left];
    }
}


int find(int a, vector<int>& parent) {
    if(parent[a] == a) {
        return a;
    }
    return parent[a] = find(parent[a], parent); 
}

void union_sets(int a, int b, vector<int>& parent, vector<int>& size) {
    a = find(a, parent);
    b = find(b, parent);

    if(a != b) {
        if(size[a] < size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a]  += size[b];
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for(int i = 0; i < m; i++) {
        int l ,r , c;
        cin >> l >> r >> c;
        
        l--; r--;
        for(int u = l; u <=r; u++) {
            for(int v = u + 1; v <= r; v++) {
                edges.push_back({u, v,c});
            }
        }   
    }

    mergeSort(edges, 0, edges.size() - 1);


    vector<int> parent(n);
    vector<int> size(n, 0);

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    long long mst_cost = 0;
    int edge_count = 0;

    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if(find(u, parent) != find(v, parent)) {
            union_sets(u, v, parent, size);
            mst_cost += weight;
            edge_count++;
        }
        if(edge_count == n - 1) {
            break;
        }
    }

    cout << mst_cost << endl;
}
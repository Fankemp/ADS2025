#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1') {
        return;
    }
    
    grid[i][j] = '0';
    
    dfs(grid, i - 1, j, n, m);
    dfs(grid, i + 1, j, n, m);
    dfs(grid, i, j - 1, n, m);
    dfs(grid, i, j + 1, n, m);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    int islands = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                islands++;
                dfs(grid, i, j, n, m);
            }
        }
    }
    
    cout << islands << endl;
    
    return 0;
}
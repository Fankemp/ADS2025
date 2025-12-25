#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    queue<pair<int,int>> q;
    vector<vector<int>> dist(m, vector<int>(n, -1));

    int cntMush = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 2) {
                q.push(make_pair(i, j));
                dist[i][j] = 0;
            } else if (a[i][j] == 1) {
                cntMush++;
            }
        }
    }

    if (cntMush == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int ans = 0;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int,int> p = q.front(); 
        q.pop();
        int x = p.first;
        int y = p.second;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;

            if (a[nx][ny] == 1 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
                cntMush--;
                if (dist[nx][ny] > ans)
                    ans = dist[nx][ny];
            }   
        }
    }

    if (cntMush > 0) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}
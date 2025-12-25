#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<int> vec(t);

    for (int i = 0; i < t; i++) {
        cin >> vec[i];
    }

    int n, m;
    cin >> n >> m;
    vector<vector<int>> snake(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> snake[i][j];
        }
    }

    for (int i = 0; i < t; i++) {
        bool found = false;
        for (int r = 0; r < n && !found; r++) {
            for (int c = 0; c < m; c++) {
                if (snake[r][c] == vec[i]) {
                    cout << r << " " << c << '\n';
                    found = true;
                    break;
                }
            }
        }
        if (!found) cout << -1 << '\n';
    }
    return 0;
}

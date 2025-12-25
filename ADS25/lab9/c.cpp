#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefixFunction(const string& pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

vector<int> kmpSearchAll(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> pi = prefixFunction(pattern);
    vector<int> positions;

    int j = 0;
    for (int i = 0; i < n; i++) { 
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            positions.push_back(i - m + 1);
            j = pi[j - 1];
        }
    }

    return positions;
}

int main() {
    string A, B;
    cin >> A >> B;
    int n = A.size();

    if (B.size() != n) {
        cout << -1;
        return 0;
    }

    string text = A + A;
    vector<int> pos = kmpSearchAll(text, B);

    int ans = 1e9;
    for (int start : pos) {
        if (start < n) { 
            int shiftRight = (n - start) % n;
            ans = min(ans, shiftRight);
        }
    }

    if (ans == 1e9) cout << -1;
    else cout << ans;

    return 0;
}

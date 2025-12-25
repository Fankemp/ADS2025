#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    vector<int> pi(n, 0);
    
    // Вычисляем префикс-функцию
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    
    // Минимальный период
    int period = n - pi[n - 1];
    cout << period << endl;
    
    return 0;
}
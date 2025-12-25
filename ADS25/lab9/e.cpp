#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Функция для вычисления префикс-функции
vector<int> computePrefixFunction(const string& s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        int k;
        cin >> s >> k;

        // Вычисляем префикс-функцию для строки
        vector<int> pi = computePrefixFunction(s);
        int overlap = pi[s.size() - 1]; // наибольший суффикс, который является префиксом

        // Длина минимальной строки, которая будет содержать подстроку s как минимум k раз
        int length = s.size() + (k - 1) * (s.size() - overlap);
        
        cout << length << endl;
    }

    return 0;
}
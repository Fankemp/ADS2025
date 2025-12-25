#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    long long result = 0;
    
    // Перебираем все возможные длины для a и c
    for (int len = 1; len <= n - 2; len++) {
        // Проверяем, что первые len символов равны последним len символам
        bool equal = true;
        for (int i = 0; i < len; i++) {
            if (s[i] != s[n - len + i]) {
                equal = false;
                break;
            }
        }
        if (!equal) continue;
        
        // Строка a = s[0..len-1]
        // Ищем вхождения a в средней части s[len..n-len-1]
        
        // Строим префикс-функцию для строки a
        vector<int> pi_pattern(len, 0);
        for (int i = 1; i < len; i++) {
            int j = pi_pattern[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = pi_pattern[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi_pattern[i] = j;
        }
        
        // Ищем вхождения pattern в text используя KMP
        int j = 0;
        for (int i = len; i <= n - len - 1; i++) {
            while (j > 0 && s[i] != s[j]) {
                j = pi_pattern[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            if (j == len) {
                // Нашли вхождение
                result++;
                j = pi_pattern[j - 1]; // продолжаем поиск
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}
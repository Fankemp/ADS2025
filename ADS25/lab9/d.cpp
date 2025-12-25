#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Функция для нахождения максимальной длины суффикса prevCity, который является префиксом city
int findMaxSuffixPrefixLength(string prevCity, string city) {
    int maxLen = 0;
    int n = prevCity.size();
    int m = city.size();
    
    // Перебираем все возможные длины суффиксов prevCity
    for (int len = 1; len <= n && len <= m; len++) {
        // Берем суффикс длины len из prevCity
        string suffix = prevCity.substr(n - len, len);
        // Берем префикс длины len из city
        string prefix = city.substr(0, len);
        
        // Сравниваем (учитывая регистр)
        bool match = true;
        for (int i = 0; i < len; i++) {
            if (tolower(suffix[i]) != tolower(prefix[i])) {
                match = false;
                break;
            }
        }
        
        if (match) {
            maxLen = len;
        }
    }
    
    return maxLen;
}

int main() {
    string prevCity;
    int n;
    cin >> prevCity >> n;

    vector<string> cities(n);
    for (int i = 0; i < n; ++i) {
        cin >> cities[i];
    }

    // Находим максимальную длину среди всех городов
    int maxLength = 0;
    for (int i = 0; i < n; ++i) {
        int current = findMaxSuffixPrefixLength(prevCity, cities[i]);
        if (current > maxLength) {
            maxLength = current;
        }
    }

    // Собираем все города с максимальной длиной
    vector<string> result;
    for (int i = 0; i < n; ++i) {
        int current = findMaxSuffixPrefixLength(prevCity, cities[i]);
        if (current == maxLength && maxLength > 0) {
            result.push_back(cities[i]);
        }
    }

    // Вывод результата
    cout << result.size() << endl;
    for (string city : result) {
        cout << city << endl;
    }

    return 0;
}
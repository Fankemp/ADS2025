#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // чтобы убрать \n после числа

    for (int t = 0; t < n; t++) {
        string line;
        getline(cin, line); // читаем всю строку

        stringstream ss(line);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        for (string& w : words) cout << w << " ";
        cout << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    queue<int> sakayanagi, katsuragi;


    for (int i = 0; i < n; i++) {
        if (s[i] == 'S')
            sakayanagi.push(i);
        else
            katsuragi.push(i);
    }

    while (!sakayanagi.empty() && !katsuragi.empty()) {
        int i = sakayanagi.front(); sakayanagi.pop();
        int j = katsuragi.front(); katsuragi.pop();

        if (i < j) {
            sakayanagi.push(i + n);
        } else {
            katsuragi.push(j + n);
        }
    }

    if (sakayanagi.empty())
        cout << "KATSURAGI\n";
    else
        cout << "SAKAYANAGI\n";

    return 0;
}

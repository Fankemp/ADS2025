#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0;
        return 0;
    }

    vector<long long> path;
    long long x = b;

    // Build path backwards from b to a
    while (x > a) {
        path.push_back(x);
        if (x % 2 == 0) x /= 2;  // reverse of *2
        else x++;               // reverse of -1
    }

    // Now x <= a, add remaining increments
    while (x < a) {
        path.push_back(x);
        x++;
    }

    // Now path holds sequence backward from b to a; reverse it
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (long long v : path) cout << v << " ";

    return 0;
}
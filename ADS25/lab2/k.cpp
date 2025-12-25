#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void processStream(int N, const string &stream) {
    unordered_map<char, int> count;
    queue<char> q;

    for (int i = 0; i < N; i++) {
        char currentChar = stream[i];
        
        count[currentChar]++;

        if (count[currentChar] == 1) {
            q.push(currentChar);
        }
        
        while (!q.empty() && count[q.front()] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        string stream;
        for (int i = 0; i < N; i++) {
            char x;
            cin >> x;
            stream.push_back(x);
        }

        processStream(N, stream);
    }
    return 0;
}

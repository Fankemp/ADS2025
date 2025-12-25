#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> prefixFunction(string& pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);

    int j = 0;
    for(int i = 1; i < m; i++) {
        while(j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if(pattern[j] == pattern[i]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}


int KMP_Search(string& text, string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> pi = prefixFunction(pattern);

    int j = 0;
    int count = 0;

    for(int i = 0; i < n; i++) {
        while(j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }

        if(text[i] == pattern[j]) {
            j++;
        }

        if(j == m) {
           count ++;
           j = pi[j - 1];
        }
    }

    return count;
}



int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    string password;
    cin >> password;

    if(n <= KMP_Search(password, s)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}